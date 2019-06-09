#pragma once
class BSTNode
{
public:
	int key;
	BSTNode* left, *right;
public:
	BSTNode() = delete;
	BSTNode(int key);
	//BSTNode (int key, BSTNode* left, BSTNode* right);
	~BSTNode();
	bool isLeaf() { if (this && left == nullptr && right == nullptr)return true; return false; }
	void visit();
};

