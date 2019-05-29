#include "Edge.h"
#include "GraphNode.h"


Edge::Edge(GraphNode* dest)
{
	this->dest = dest;
	peer = nullptr;
	weight = 0;
}

Edge::Edge(GraphNode* dest, int weight) {
	this->dest = dest;
	peer = nullptr;
	this->weight = weight;
}

Edge::~Edge()
{
}
