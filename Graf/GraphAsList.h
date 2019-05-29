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
	bool insertEdge(int startNode, int endNode);
	bool deleteNode(int key);
	bool deleteEdge(int startNode, int endNode);
private:
	void deleteEdge(GraphNode* sourceNode, Edge* prev, Edge* current);
	void deleteExitingEdges(GraphNode* source);
};

