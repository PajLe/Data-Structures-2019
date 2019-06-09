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

	// zadaci sa kolokvijuma:

	bool balanced(); // SP_Kol_II_2018 zad: 1b

private:
	BSTNode* findPlaceToInsert(BSTNode* prev, BSTNode* temp, int key);
	void deleteSubtree(BSTNode* node);
	int nodeHeight(BSTNode* node);
	bool balanced(BSTNode* node, int* height);
};

