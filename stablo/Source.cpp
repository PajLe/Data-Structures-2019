#include "BSTNode.h"
#include "BSTree.h"
#include <iostream>
#include "BinaryMinHeap.h"

int main() {
	/*BSTree* a = new BSTree();
	a->insert(7);
	a->insert(3);
	a->insert(8);
	a->insert(1);
	a->insert(5);
	a->insert(9);
	a->insert(2);
	a->insert(6);
	//preorder> 7 3 1 2 5 6 8 9
	a->preorder(a->root);
	std::cout << std::endl;
	delete a;*/

	BinaryMinHeap* b = new BinaryMinHeap(100);
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
	delete b;
}