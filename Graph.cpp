#include "Graph.h"

//
// Graph
//
Graph::Graph (void)
{
}

//
// ~Graph
//
Graph::~Graph (void)
{
	// delete vertices to free memory.
	for (size_t i = 0; i < vertices_.size(); i++)
	{
		delete vertices_[i];
	}
}

//
// insert (Vertex *)
//
void Graph::insert (Vertex * v)
{
	// flag to check if vertex is there in graph.
	bool flag=true;
	// finds if vertex is there in graph.
	for (size_t i = 0; i < vertices_.size(); i++)
	{
		if (vertices_[i]->name()==v->name())
		{
			flag=false;
			break;
		}
	}
	// if vertex is not present in graph push the vertex in graph.
	if (flag)
	{
		vertices_.push_back(v);
	}
	
}

//
// find_vertex (Vertex *)
//
Vertex * Graph::find_vertex (Vertex * v)
{
	// does a basic search to find and return the reference to the found vertex.
	for (size_t i = 0; i < vertices_.size(); i++)
	{
		if (vertices_[i]->name()==v->name())
		{
			return vertices_[i];
		}
	}
	return 0;
}

//
// print_graph (std::string &)
//
void Graph::print_graph (std::string & graph_name)
{
	// calls the print edges function to print out in the Graphviz DOT format.
	std::ofstream file(graph_name);
	file << "digraph G {"<<std::endl;
	for (size_t i = 0; i < vertices_.size(); i++)
	{
		this->vertices_[i]->print_edges(file);
	}
	file<<"}"<<std::endl;
	file.close();
}