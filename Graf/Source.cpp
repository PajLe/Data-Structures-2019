#include "GraphAsList.h"
#include <iostream>

int main() {
	GraphAsList* a = new GraphAsList();
	a->insertNode(4);
	a->insertNode(3);
	a->insertNode(2);
	a->insertNode(1);
	a->insertEdge(1, 3);
	a->insertEdge(1, 2);
	a->insertEdge(1, 4);
	a->insertEdge(2, 1);
	a->insertEdge(3, 1);
	a->insertEdge(4, 1);
	a->insertEdge(4, 2);

	a->findEdge(4, 1);
	a->findNode(1);

	a->print();
	a->deleteEdge(3, 1);
	a->print();
	a->insertEdge(3, 1);

	a->deleteNode(1);
	a->print();
	a->insertNode(1);
	a->print();

	a->deleteEdge(4, 2);
	a->print();
	a->deleteNode(4);
	a->print();


	delete a;
	return 0;
}