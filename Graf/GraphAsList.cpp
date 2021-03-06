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

//operacija dodavanja cvora O(n) 
bool GraphAsList::insertNode(int key, int vremePresedanja) {
	if (findNode(key)) return false; // cvor sa ovim kljucem vec postoji
	GraphNode* newNode = new GraphNode(key, vremePresedanja);
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

bool GraphAsList::insertEdge(int startNode, int endNode, int weight) {
	GraphNode* tempStart = findNode(startNode);
	if (!tempStart) return false;
	GraphNode* tempEnd = findNode(endNode);
	if (!tempEnd) return false;

	Edge* newEdge = new Edge(tempEnd, weight);
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

std::vector<GraphNode*>* GraphAsList::getReachable(int idAerodroma, int time) {
	std::vector<GraphNode*>* list = new std::vector<GraphNode*>();
	GraphNode* temp = start;
	while (temp) {
		temp->status = 0;
		temp = temp->next;
	}

	GraphNode* aero = findNode(idAerodroma);
	if (aero) aero->status = 2;
	else return list;
	reachable(aero, time, *list);

	return list;
}

void GraphAsList::reachable(GraphNode* node, int time, std::vector<GraphNode*>& list) {
	if (time < 0) return;
	
	Edge* e = node->edges;
	
	while (e) {
		if (e->dest->status == 0 && e->weight <= time) {
			list.push_back(e->dest);
			e->dest->status = 1; // status = 1 znaci da je cvor ubacen u listu;  u sledecem nivou rekurzije ne treba da se ubacuje ponovo
		}
		int prevStatus = e->dest->status; // pamtimo status cvora u trenutnoj dubini rekurzije
		if (e->dest->status < 2 && e->weight < time) { // ako cvor ima status = 2 ili se ne moze doci do njega (ili se moze doci do njega, ali se ne moze dalje ici), ne treba ga dalje "obilaziti"
			e->dest->status = 2; // ako smo obisli cvor, postavljamo status = 2 kako ga ne bismo ponovo obilazili u sledecem nivou rekurzije
			reachable(e->dest, time - e->weight - e->dest->vremePresedanja, list);
		}	

		e->dest->status = prevStatus;
		e = e->peer;
	}

}

void GraphAsList::dobiliLoptu() {
	if (!start) return;
	GraphNode* temp = start;
	while (temp) {
		temp->status = 0;
		temp = temp->next;
	}
	temp = start;
	while (temp) {
		if (temp->status == 0 && temp->edges) {
			temp->visit();
			temp->status = 1;
		}
		dfs(temp);
		temp = temp->next;
	}

}

void GraphAsList::dfs(GraphNode* node) {
	/* septembar 2019.
	*	cilj obilaska grafa je, uglavnom, da svaki čvor bude posećen tačno jednom 
	* 	ovaj dfs posećuje čvorove ulazniStepen(čvor) puta
	*	samim tim ne bi trebalo da se primenjuje
	*	jedinu svrhu ima kad uzimamo u obzir puteve kao u slučaju reachable funkcije
	*/
	if (!node) return;

	Edge* e = node->edges;

	while (e) {
		
		if (e->dest->status == 0) {
			e->dest->visit();
			e->dest->status = 1;
		}
		int prevStatus = e->dest->status;
		if (e->dest->status < 2) {
			e->dest->status = 2;
			dfs(e->dest);
		}
		e->dest->status = prevStatus;
		e = e->peer;
	}
}

int GraphAsList::izlazniStepen(GraphNode* node) {
	if (!node) return 0;
	node->status = 0;
	Edge* e = node->edges;
	while (e) {
		node->status++;
		e = e->peer;
	}
	return node->status;
}

GraphNode* GraphAsList::findMaxReachable() {
	if (!start) return nullptr;
	GraphNode* temp = start;
	while (temp) {
		temp->status = 0;
		temp = temp->next;
	}

	temp = start;
	GraphNode* maxReachable = temp;
	int nr = findNumReachable(temp);

	temp = temp->next;
	while (temp) { // moramo od svakog cvora da nadjemo maxReachable jer ne znamo da li je graf povezan ili ne
				   // ako graf jeste povezan, svakako bi moralo ovako osim ako ne dodamo jos neki atribut u klasi GraphNode u koji bi se pamtio numReachable
				   // tada bi mozda bilo moguce i samo jednim prolaskom kroz lancanu strukturu grafa
				   // a mozda samo ne znam sta pricam
		int tempNr = findNumReachable(temp);
		if (tempNr > nr) {
			nr = tempNr;
			maxReachable = temp;
		}
		temp = temp->next;
	}
	return maxReachable;
}

int GraphAsList::findNumReachable(GraphNode* node) {
	if (!node) return 0;
	int toReturn = 0;
	Edge* e = node->edges;
	while (e) {
		if (e->dest->status == 0) {
			toReturn++;
			e->dest->status = 1;
		}
		if (e->dest->status < 2) {
			e->dest->status = 2;
			toReturn += findNumReachable(e->dest);
		}
		e->dest->status = 0; // moguce da je bug i da je potrebno da u GraphAsList::findMaxReachable() treba postaviti sve statuse na 0 nakon svakog poziva  GraphAsList::findNumReachable(GraphNode* node) (sto znaci da bi slozenost bila BAR O(n^2))
							 // ali za moj test primer radi i ovo kako treba (i ne umem da smislim neki za koji ne bi radilo)
		e = e->peer;
	}
	return toReturn;
}

int GraphAsList::calcPrevious(int subjects[], int n) {
	GraphNode* temp = start;
	while (temp) {
		temp->status = 0;
		temp = temp->next;
	}

	int brp = 0;
	for (int i = 0; i < n; i++) {
		brp += brojPreduslova(findNode(subjects[i]));
	}
	return brp;
}

int GraphAsList::brojPreduslova(GraphNode* predmet) {
	if (!predmet) return 0;
	int toRet = 0;
	Edge* e = predmet->edges;
	while (e) {
		if (e->dest->status == 0) {
			toRet++;
			e->dest->status = 1;
			toRet += brojPreduslova(e->dest);
		}
		e = e->peer;
	}
	return toRet;
}
