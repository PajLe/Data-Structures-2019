#include "BSTree.h"
#include "BSTNode.h"
#include <math.h>

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


bool BSTree::balanced() {
	int height = 0;
	if (balanced(root, &height)) return true;
	return false;
}

bool BSTree::balanced(BSTNode* node, int* height) {
	if (!node)
	{
		*height = 0;
		return true;
	}
	int lh = 0, rh = 0;
	bool l, r;
	l = balanced(node->left, &lh);
	r = balanced(node->right, &rh);
	*height = (lh > rh ? lh : rh) + 1;
	if (abs(lh - rh) >= 2)
		return false;
	else return l && r;
}

int BSTree::nodeHeight(BSTNode* node) { // vraca visinu cvora node u odnosu na najveci nivo podstabla ciji je koren node; konvencija: cvor u najvecem nivou je na visini 1
	if (!node) return 0;
	int left = nodeHeight(node->left) + 1;
	int right = nodeHeight(node->right) + 1;
	return (right > left) ? right : left;
}

int BSTree::longestLeftPath(BSTNode* root, BSTNode** start) {
	if (!root) return 0;
	int goLeft = longestLeftPath(root->left, start) + 1;
	int goRight = longestLeftPath(root->right, start);

	if(goLeft > goRight){
		*start = root; 
		return goLeft; 
	}
	return goRight;
}