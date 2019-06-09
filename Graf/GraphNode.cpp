#include "GraphNode.h"
#include "Edge.h"
#include <iostream>

GraphNode::GraphNode(int key) {
	this->key = key;
	vremePresedanja = 0;
	status = 0;
	next = nullptr;
	edges = nullptr;
}

GraphNode::GraphNode(int key, int vremePresedanja) {
	this->key = key;
	this->vremePresedanja = vremePresedanja;
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

