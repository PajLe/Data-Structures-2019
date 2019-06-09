#include "BSTNode.h"
#include <iostream>


BSTNode::BSTNode(int key)
{
	this->key = key;
	left = nullptr;
	right = nullptr;
}


BSTNode::~BSTNode()
{
}

void BSTNode::visit() {
	std::cout << key << " ";
}
