#include "GraphAsList.h"
#include "GraphNode.h"
#include <iostream>

int main() {
	/*GraphAsList* a = new GraphAsList();
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


	delete a;*/

	/*GraphAsList* avio = new GraphAsList();
	avio->insertNode(1, 50);
	avio->insertNode(2, 20);
	avio->insertNode(3, 30);
	avio->insertNode(4, 11);
	avio->insertNode(5, 15);
	avio->insertNode(6, 40);
	avio->insertNode(7, 100);
	avio->insertNode(8, 111);


	avio->insertEdge(1, 2, 142);
	avio->insertEdge(2, 1, 142);

	avio->insertEdge(1, 5, 849);
	avio->insertEdge(5, 1, 849);

	avio->insertEdge(2, 3, 1099);
	avio->insertEdge(3, 2, 1099);

	avio->insertEdge(2, 4, 1387);
	avio->insertEdge(4, 2, 1387);

	avio->insertEdge(3, 4, 1120);
	avio->insertEdge(4, 3, 1120);

	avio->insertEdge(4, 5, 802);
	avio->insertEdge(5, 4, 802);

	avio->insertEdge(4, 7, 1233);
	avio->insertEdge(7, 4, 1233);

	avio->insertEdge(5, 7, 1743);
	avio->insertEdge(7, 5, 1743);

	avio->insertEdge(5, 6, 1843);
	avio->insertEdge(6, 5, 1843);

	avio->insertEdge(6, 7, 337);
	avio->insertEdge(7, 6, 337);

	avio->insertEdge(8, 7, 2555);
	avio->insertEdge(7, 8, 2555);

	std::vector<GraphNode*>* a = avio->getReachable(1, 1302);
	for (int i = 0; i < a->capacity(); i++) {
		std::cout << a->at(i)->key << " ";
	}
	delete a;
	delete avio;*/

	GraphAsList* b = new GraphAsList();
	b->insertNode(1);
	b->insertNode(2);
	b->insertNode(3);
	b->insertNode(4);
	b->insertNode(5);
	b->insertNode(6);
	b->insertNode(7);
	b->insertNode(8);
	b->insertNode(9);
	b->insertNode(10);
	b->insertNode(11);

	b->insertEdge(5, 6);
	b->insertEdge(6, 8);
	b->insertEdge(8, 1);
	b->insertEdge(1, 8);
	b->dobiliLoptu();
	delete b;
}