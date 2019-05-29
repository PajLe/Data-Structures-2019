#pragma once
class Edge
{
public:
	class GraphNode* dest; // destination node
	Edge* peer; // sledeca odlazna grana u listi
	int weight;
public:
	Edge() = delete;
	Edge(GraphNode* dest);
	//Edge(GraphNode* dest, Edge* peer);
	Edge(GraphNode* dest, int weight);
	//Edge(GraphNode* dest, Edge* peer, int weight);
	~Edge();
};

