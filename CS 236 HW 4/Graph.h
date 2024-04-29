#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <limits>

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

private:
	int numVertices;
	int numEdges;
	int numRelaxation;
	int sourceVertex;
	vector<Edge> edgeList;
	vector<int> distances;

};




#endif
