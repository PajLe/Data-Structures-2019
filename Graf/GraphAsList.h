#pragma once
#include <iostream>
#include <vector>

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
	void print();

	bool insertNode(int key, int vremePresedanja);
	bool insertEdge(int startNode, int endNode, int weight);

	// zadaci sa kolokvijuma:

	std::vector<GraphNode*>* getReachable(int idAerodroma, int time); // SP_Kol_II_2016 zad: 3b
	void dobiliLoptu(); // SP_Kol_II_2018 zad: 2b
private:
	void deleteEdge(GraphNode* sourceNode, Edge* prev, Edge* current);
	void deleteExitingEdges(GraphNode* source);

	void reachable(GraphNode* node, int time, std::vector<GraphNode*>& list);
	void dfs(GraphNode* node);
};

