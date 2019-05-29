#include "GraphAsList.h"
#include "GraphNode.h"
#include "Edge.h"



GraphAsList::GraphAsList()
{
	start = nullptr;
	nodeNum = 0;
}

GraphAsList::~GraphAsList()
{
}

GraphNode* GraphAsList::findNode(int key) {
	GraphNode* temp = start;
	while (temp) {
		if (temp->key == key) return temp;
		temp = temp->next;
	}

	return nullptr;
}

Edge* GraphAsList::findEdge(int startNode, int endNode) {
	GraphNode* tempStart = findNode(startNode);
	if (!tempStart) return nullptr;
	
	Edge* tempEdge = tempStart->edges;
	while (tempEdge) {
		if (tempEdge->dest->key == endNode) return tempEdge;
		tempEdge = tempEdge->peer;
	}

	return nullptr;
}

//operacija dodavanja cvora O(nCvorova) ?!
bool GraphAsList::insertNode(int key) {
	if (findNode(key)) return false; // cvor sa ovim kljucem vec postoji
	GraphNode* newNode = new GraphNode(key);
	newNode->next = start;
	start = newNode;
	nodeNum++;
}