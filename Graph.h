//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <vector>
#include <fstream>

#include "Vertex.h"
#include "Edge.h"

/**
* @class Graph
*
* Basic implementation of Graph class for creating a simple Graph.
*/
class Graph
{
public:
	/// Constructor
	Graph (void);

	/// Destructor
	~Graph (void);

	/**
	* Method for adding a vertex to the graph.
	*
	* @param[in]    Vertex *        v i.e., Vertex of Graph.
	*/
	void insert (Vertex * v);

	/**
	* Method for finding a vertex in the graph.
	*
	* @param[in]    Vertex *        v i.e., Vertex of Graph.
	* @return       Vertex *        The found Vertex reference.
	*/
	Vertex * find_vertex (Vertex * v);

	/**
	* Method for printing the graph.
	*
	* @param[in]    std::string &        Name of file for graphviz.
	*/
	void print_graph (std::string & graph_name);


private:

	// Storing the vertices of the graph.
	std::vector<Vertex *> vertices_;
};

#endif // !_GRAPH_H_