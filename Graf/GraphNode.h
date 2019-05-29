#pragma once
class GraphNode
{
public:
	int key;
	int status; // 0 - neobradjen, 1 - obradjen
	GraphNode* next; // sledeci u listi, a ne sledeci s kojim je povezan
	class Edge* edges; // izlazni potezi
public:
	GraphNode() = delete;
	GraphNode(int key);
	//GraphNode(int key, GraphNode* next);
	//GraphNode(int key, GraphNode* next, Edge* edges);
	~GraphNode();
	void visit();
};

