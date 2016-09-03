#include "Vertex.h"

//
// Vertex
//
Vertex::Vertex ()
{
}

//
// Vertex (std::string)
//
Vertex::Vertex (std::string name)
	:name_(name)
{
}

//
// ~Vertex
//
Vertex::~Vertex()
{
}

//
// add_edge (Vertex *)
//
void Vertex::add_edge (Vertex * destination)
{
	Edge new_edge(this, destination);
	bool flag=true;
	// if edge exists in the increase the weight of the particular edge.
	for (size_t i = 0; i < edges_.size(); i++)
	{
		if (edges_[i].origin()->name()==this->name() && edges_[i].destination()->name()==destination->name())
		{
			edges_[i].increase_weight();
			flag=false;
			break;
		}
	}
	// if edge is not found add it onto the graph.
	if (flag)
	{
		edges_.push_back(new_edge);
	}
}

//
// print_edges (std::ofstream &)
//
void Vertex::print_edges (std::ofstream & file)
{
	// if there are no edges for the graph then the node is single node.
	if (edges_.size()==0)
	{
		file << "\"" << this->name() << "\"" << std::endl;
	}
	// if there are edges then print out the connections as per Graphviz DOT format into file.
	else
	{
		for (size_t i = 0; i < edges_.size(); i++)
		{
			Edge e = edges_[i];
			file << "\"" << this->name() << "\"" << " -> ";
			file<< "\""<<e.destination()->name()<< "\""<<" [label=\""<<e.weight()<<"\"];"<<std::endl;
		}
	}
}

//
// name (void)
//
std::string Vertex::name ()
{
	return this->name_;
}

//
// edges (void)
//
std::vector<Edge> Vertex::edges ()
{
	return this->edges_;
}