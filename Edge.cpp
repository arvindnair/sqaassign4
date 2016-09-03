#include "Edge.h"
#include "Vertex.h"

//
// Edge
//
Edge::Edge (void)
{
}

//
// Edge (Vertex *, Vertex *)
//
// when edge is created the weight is 1.
Edge::Edge (Vertex * origin, Vertex * destination)
	:origin_(origin),
	destination_(destination),
	weight_(1)
{
}

//
// ~Edge
//
Edge::~Edge (void)
{
}

//
// origin
//
Vertex * Edge::origin (void)
{
	return this->origin_;
}

//
// destination
//
Vertex * Edge::destination (void)
{
	return this->destination_;
}

//
// increase_weight
//
void Edge::increase_weight (void)
{
	this->weight_++;
}

//
// weight
//
int Edge::weight (void)
{
	return this->weight_;
}
