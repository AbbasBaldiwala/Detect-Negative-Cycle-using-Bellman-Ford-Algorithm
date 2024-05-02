#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

using namespace std;

const int MAX_INT = INT_MAX; //cant have distance longer than this, set initial distances to as far as possible

struct Edge {
	int source;
	int destination;
	int weight;
};

class Graph {
public:
	Graph(int numVert, int numEdges, int source); //constructor
	void CreateEdgeList(); //gets input for the edges
	void PrintVertexDistances(); //prints the distacnes from source vertex
	void FindShortestPath(); //updates distances to find the shortest path
	void AddEdge(int source, int destination); //adds an edge to the adjacency list
	void FindCycle(int target, int current); //uses recursion to find the negative edge cycle

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
