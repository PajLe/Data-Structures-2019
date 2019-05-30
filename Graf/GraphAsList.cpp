#include "GraphAsList.h"
#include "GraphNode.h"
#include "Edge.h"
#include <iostream>


GraphAsList::GraphAsList()
{
	start = nullptr;
	nodeNum = 0;
}

GraphAsList::~GraphAsList()
{
	GraphNode* temp = start;
	while (temp) {
		deleteExitingEdges(temp);
		GraphNode* toDel = temp;
		temp = temp->next;
		delete toDel;
	}
	start = nullptr;
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

//operacija dodavanja cvora O(n) 
bool GraphAsList::insertNode(int key) {
	if (findNode(key)) return false; // cvor sa ovim kljucem vec postoji
	GraphNode* newNode = new GraphNode(key);
	newNode->next = start;
	start = newNode;
	nodeNum++;
	return true;
}

bool GraphAsList::insertEdge(int startNode, int endNode) {
	GraphNode* tempStart = findNode(startNode);
	if (!tempStart) return false;
	GraphNode* tempEnd = findNode(endNode);
	if (!tempEnd) return false;

	Edge* newEdge = new Edge(tempEnd);
	newEdge->peer = tempStart->edges;
	tempStart->edges = newEdge;
	return true;
}

bool GraphAsList::deleteNode(int key) {
	if (!start) return false;

	GraphNode* prevNode = nullptr;
	GraphNode* tempNode = start;
	GraphNode* toDel = nullptr;
	bool found = false;

	while (tempNode) {
		if (tempNode->key == key) { // pronadjen key u listi cvorova
			found = true;
			deleteExitingEdges(tempNode); // brise sve odlazne grane u listi grana trenutnog cvora
			if (tempNode == start) {
				start = tempNode->next;
			}
			else {
				prevNode->next = tempNode->next;
			}
			toDel = tempNode;
		}
		else {
			Edge* prevEdge = nullptr;
			Edge* tempEdge = tempNode->edges;
			while (tempEdge) {
				// prolazimo kroz sve grane trenutnog cvora (tempNode)
				// i brisemo one koje idu ka cvoru 'key'

				if (tempEdge->dest->key == key) {
					deleteEdge(tempNode, prevEdge, tempEdge);
					//found = true; // ako smo pronasli poteg ka cvoru, cvor sigurno postoji
					break; // nema dvostrukih grana u istom smeru!
				}
				prevEdge = tempEdge;
				tempEdge = tempEdge->peer;
			}
		}
		
		prevNode = tempNode;
		tempNode = tempNode->next;
	}

	if (toDel) {
		delete toDel;
		nodeNum--;
	}
	return found;
}

void GraphAsList::deleteExitingEdges(GraphNode* source) {
	Edge* tempEdge = source->edges;
	while (tempEdge) {
		Edge* toDel = tempEdge;
		tempEdge = tempEdge->peer;
		delete toDel;
	}
	source->edges = nullptr;
}

void GraphAsList::deleteEdge(GraphNode* sourceNode, Edge* prev, Edge* current) {
	if (!prev) {
		sourceNode->edges = current->peer;
	}
	else {
		prev->peer = current->peer;
	}
	delete current;
}

bool GraphAsList::deleteEdge(int startNode, int endNode) {
	GraphNode* tempStart = findNode(startNode);
	if (!tempStart) return false;

	Edge* searchEdge = tempStart->edges;
	if (searchEdge->dest->key == endNode) { //endNode je prvi u listi odlaznih cvorova
		tempStart->edges = searchEdge->peer;
		delete searchEdge; return true;
	}
	Edge* prev = searchEdge;
	searchEdge = searchEdge->peer;
	
	while (searchEdge) { //trazimo endNode u listi grana cvora startNode
		if (searchEdge->dest->key == endNode) {
			prev->peer = searchEdge->peer;
			delete searchEdge; return true;
		}
		prev = searchEdge;
		searchEdge = searchEdge->peer;
	}

	return false;
}

void GraphAsList::print() {
	GraphNode* ptr = start;
	while (ptr) {
		std::cout << ptr->key << " -> ";
		Edge* tmpEdge = ptr->edges;
		while (tmpEdge) {
			std::cout << tmpEdge->dest->key << "|";
			tmpEdge = tmpEdge->peer;
		}
		std::cout << "\r\n";
		ptr = ptr->next;
	}
}