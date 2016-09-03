//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _VERTEX_H_
#define _VERTEX_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Edge.h"

/**
 * @class Vertex
 *
 * Basic implementation of Vertex class for creating Vertices of Graph class.
 */
class Vertex
{
public:
	/// Constructor
	Vertex();

	/// Initializing Constructor
	Vertex (std::string name);

	/// Destructor
	~Vertex();

  /**
   * Method for adding an edge to the Vertex.
   *
   * @param[in]    Vertex *        destination i.e., Vertex of Graph.
   */
	void add_edge (Vertex * destination);

  /**
   * Method for printing the edges of the Vertex.
   *
   * @param[in]    std::ofstream &        file i.e., File to be written into.
   */
	void print_edges (std::ofstream & file);

  /**
   * Method for retrieving the name of the Vertex.
   *
   * @return       std::string        The name of the Vertex.
   */
	std::string name ();

  /**
   * Method for retrieving the list of the Edges for the current vertex.
   *
   * @return       std::string        The list of edges for vertex.
   */
	std::vector<Edge> edges ();

private:
	// Name of the vertex.
	std::string name_;

	// List of edges for vertex.
	std::vector<Edge> edges_;

};


#endif // !_VERTEX_H_