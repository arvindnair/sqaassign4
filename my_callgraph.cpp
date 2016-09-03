#include "pin++/Callback.h"
#include "pin++/Routine_Instrument.h"
#include "pin++/Routine.h"
#include "pin++/Pintool.h"
#include "pin++/Symbol.h"
#include "Graph.h"
#include "Vertex.h"

#include <fstream>
#include <stack> 
#include <string>
#include <algorithm>
#include <cctype>

/**
* @class function_call_start
*/
// Callback to be called before routine call.
class function_call_start : public OASIS::Pin::Callback <function_call_start (void)>
{
public:
	function_call_start (std::ofstream & file, std::string node_name, std::stack<std::string> & node_stack, Graph & g)
		: file_ (file),
		node_name_ (node_name),
		node_stack_(node_stack),
		g_(g)
	{

	}

	void handle_analyze (void)
	{
		Vertex * v1=new Vertex(this->node_name_);
		g_.insert(v1);
		if (!node_stack_.empty())
		{
			Vertex * temp=new Vertex(node_stack_.top());
			g_.find_vertex(temp)->add_edge(v1);
		}
		node_stack_.push(this->node_name_);
		
		// Print the push into file for checking purposes. 
		this->file_ << "  push into stack : " << this->node_name_ << std::endl;
	}

private:
	std::ofstream & file_;
	// Used to store the routine name.
	std::string node_name_;
	std::stack<std::string> & node_stack_;
	Graph & g_;
};

/**
* @class function_call_return
*/
// Callback to be called after routine call.
class function_call_return : public OASIS::Pin::Callback <function_call_return (void)>
{
public:
	function_call_return (std::ofstream & file, std::string node_name, std::stack<std::string> & node_stack)
		: file_ (file),
		node_name_ (node_name),
		node_stack_(node_stack)
	{
	}


	void handle_analyze (void)
	{
		// Check if the stack is empty before checking top and popping.
		if (!node_stack_.empty())
		{
			std::string node_name  = node_stack_.top();
			node_stack_.pop();

			// Print the pop into file for checking purposes. 
			this->file_ << "  pop from stack : " << node_name << std::endl;
		}
	}

private:
	std::ofstream & file_;
	// Used to store the routine name.
	std::string node_name_;
	std::stack<std::string> & node_stack_;
};

/**
* @class Instruction
*/
class Instruction : public OASIS::Pin::Routine_Instrument <Instruction>
{
public:

	Instruction (std::ofstream & file, std::stack<std::string> & node_stack, Graph & g)
		: file_ (file),
		node_stack_ (node_stack),
		g_(g)
	{

	}

	void handle_instrument (const OASIS::Pin::Routine & rtn)
	{
		// remove unwanted characters from routine name.
		std::string rtn_name = OASIS::Pin::Symbol::undecorate (rtn.name (), UNDECORATION_NAME_ONLY);
		OASIS::Pin::Routine_Guard guard (rtn);
		
		// inserting the instrumentation before
		function_call_start * fun_start=new function_call_start(file_, rtn_name, node_stack_,g_);
		fun_start->insert (IPOINT_BEFORE,rtn);

		// inserting the instrumentation before
		function_call_return * fun_return=new function_call_return(file_, rtn_name, node_stack_);
		fun_return->insert (IPOINT_AFTER,rtn);
	}

private:
	// passing the variables by reference.
	std::ofstream & file_;
	std::stack<std::string> & node_stack_;
	Graph & g_;
};

class my_callgraph : public OASIS::Pin::Tool <my_callgraph>
{
public:
	my_callgraph (void)
		: file_ ("my_callgraph.out"),
		inst_ (file_, node_stack_,g_)
	{
		this->init_symbols ();
		this->enable_fini_callback ();
	}

	void handle_fini (INT32)
	{
		// specify the file name for Graphviz DOT.
		std::string graph_name="my_graph.gv";
		g_.print_graph(graph_name);
		this->file_.close ();
	}

private:
	// Store the file to print the pushed and popped routine names.
	std::ofstream file_;
	// Store the routine names in stack as vertices(nodes).
	std::stack<std::string> node_stack_;
	// Graph which is generated.
	Graph g_;
	Instruction inst_;

};

DECLARE_PINTOOL (my_callgraph);