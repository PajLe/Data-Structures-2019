#include "BSTree.h"
#include "BSTNode.h"


BSTree::BSTree()
{
	root = nullptr;
	numOfElements = 0;
}


BSTree::~BSTree()
{
	deleteSubtree(root);
}

void BSTree::deleteSubtree(BSTNode* node) {
	if (!node) return;
	deleteSubtree(node->left);
	deleteSubtree(node->right);
	delete node;
}

void BSTree::insert(int key) {
	BSTNode* newNode = new BSTNode(key);
	if (!root) {
		root = newNode;
	}
	else {
		BSTNode* prev = findPlaceToInsert(nullptr, root, key);
		if (key > prev->key) prev->right = newNode;
		else prev->left = newNode;
	}
	numOfElements++;
}

BSTNode* BSTree::findPlaceToInsert(BSTNode* prev, BSTNode* current, int key) {
	while (current) {
		prev = current;
		if (key > current->key)
			current = current->right;
		else current = current->left;
	}
	return prev;
}

void BSTree::preorder(BSTNode* node) {
	if (node) {
		node->visit();
		preorder(node->left);
		preorder(node->right);
	}
}