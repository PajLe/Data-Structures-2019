#pragma once
class GraphAsList
{
	class GraphNode* start;
	int nodeNum;
public:
	GraphAsList();
	~GraphAsList();
	GraphNode* findNode(int key);
	class Edge* findEdge(int startNode, int endNode);
	bool insertNode(int key);
};

