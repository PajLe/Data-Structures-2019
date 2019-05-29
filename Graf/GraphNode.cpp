#include "GraphNode.h"
#include "Edge.h"
#include <iostream>

GraphNode::GraphNode(int key) {
	this->key = key;
	status = 0;
	next = nullptr;
	edges = nullptr;
}

void GraphNode::visit() {
	std::cout << key << " -> ";
}

GraphNode::~GraphNode()
{
	/*if (next) {
		delete next;
		next = nullptr;
	}
		
	if (edges) {
		delete edges;
		edges = nullptr;
	}*/
}

