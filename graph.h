#pragma once
class Graph{
private:
	int n;
	int **edge;
public:
	Graph(int size = 2);
	~Graph();
	bool isConnected(int, int);
	void addEdge(int, int);
	void BreadthFirstSearch(int, int);
	void DepthFirstSearch(int, int);
};
