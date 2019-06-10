#include "BSTNode.h"
#include "BSTree.h"
#include <iostream>
#include "BinaryMinHeap.h"

int main() {
	

	/*BinaryMinHeap* b = new BinaryMinHeap(100);
	b->insert(10);
	b->insert(17);
	b->insert(23);
	b->insert(19);
	b->insert(21);
	b->insert(55);
	b->insert(23);
	b->insert(32);
	b->insert(43);
	b->insert(67);
	b->insert(58);
	b->insert(85);
	b->printHeap();
	std::cout << std::endl;
	b->update(17, -15);
	b->printHeap();
	std::cout << std::endl;
	delete b;*/

	/*BSTree* c = new BSTree();
	c->insert(50);
	c->insert(17);
	c->insert(72);
	c->insert(12);
	c->insert(23);
	c->insert(54);
	c->insert(76);
	c->insert(9);
	c->insert(14);
	c->insert(19);
	c->insert(67);
	//preorder> 50 17 12 9 14 23 19 72 54 67 76
	c->preorder(c->root);
	std::cout << std::endl;*/

	BSTree* a = new BSTree();
	a->insert(7);
	a->insert(3);
	a->insert(8);
	a->insert(1);
	a->insert(5);
	a->insert(9);
	a->insert(2);
	a->insert(4);
	//preorder> 7 3 1 2 5 6 8 9
	/*a->insert(7);
	a->insert(4);
	a->insert(12);
	a->insert(5);
	a->insert(10);
	a->insert(15);
	a->insert(8);*/
	a->preorder(a->root);
	BSTNode* node = nullptr;
	int longest = a->longestLeftPath(a->root, &node);
	node->visit();
	std::cout << longest << std::endl;

	/*a->insert(10);
	a->insert(11);
	a->insert(12);
	a->insert(13);
	
	a->preorder(a->root);
	std::cout << std::endl;

	std::cout << c->balanced() << std::endl;
	std::cout << a->balanced() << std::endl;
	
	delete c;*/
	delete a;
}