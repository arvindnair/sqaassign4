//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _EDGE_H_
#define _EDGE_H_

/// Forward Declaration of Vertex class.
class Vertex;

/**
 * @class Edge
 *
 * Basic implementation of Edge class for creating Edges of Vertices class.
 */
class Edge
{
public:

	/// Constructor
	Edge (void);

	Edge (Vertex * origin, Vertex * destination);

	/// Destructor
	~Edge (void);

  /**
   * Method for retrieving the origin/source vertex of the edge.
   *
   * @return       Vertex *        The origin Vertex reference.
   */
	Vertex * origin (void);

  /**
   * Method for retrieving the destination vertex of the edge.
   *
   * @return       Vertex *        The destination Vertex reference.
   */
	Vertex * destination (void);

	/**
	* Method for increasing the weight(no. of times called) of the edge.
	*
	*/
	void increase_weight (void);

	/**
	* Method for retrieving the weight(no. of times called) of the edge.
	*
	*/
	int weight (void);

private:
	Vertex * origin_;
	Vertex * destination_;
	size_t weight_;
};

#endif // !_EDGE_H_