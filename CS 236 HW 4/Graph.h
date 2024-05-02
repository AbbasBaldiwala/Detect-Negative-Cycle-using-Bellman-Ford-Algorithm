#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <limits>
#include <unordered_set>

using namespace std;

const int MAX_INT = 10000; //cant have distance longer than this

struct Edge {
	int source;
	int destination;
	int weight;
};

class Graph {
public:
	Graph(int numVert, int numEdges, int source);
	void CreateEdgeList();
	void PrintVertexDistances();
	void FindShortestPath();
	void AddEdge(int source, int destination);
	void FindCycle(int target, int current, int prev);

private:
	int numVertices;
	int numEdges;
	int numRelaxation;
	int sourceVertex;

	bool cycleFound = false;
	vector<Edge> edgeList;
	vector<int> distances;

	vector<vector<int>> adjacencyList;
	vector<bool> visited;
	vector<int> cycle;

};




#endif
