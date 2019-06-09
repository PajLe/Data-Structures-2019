#pragma once
class BSTree
{
public:
	class BSTNode* root;
	int numOfElements;
public:
	BSTree();
	~BSTree();
	void insert(int key);
	void preorder(BSTNode* node);
private:
	BSTNode* findPlaceToInsert(BSTNode* prev, BSTNode* temp, int key);
	void deleteSubtree(BSTNode* node);
};

