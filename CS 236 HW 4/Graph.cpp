#include "Graph.h"

Graph::Graph(int numV, int numE, int source) {
	numVertices = numV;
	numEdges = numE;
	distances.resize(numV, MAX_INT);
	if (source < numV) {
		sourceVertex = source;
		distances[source] = 0;
	}
	else {
		cout << "Source Vertex can only be between 0 and " << numE - 1 << ".\n";
		sourceVertex = 0;
		distances[0] = 0;
	}
	edgeList.resize(numE);
	
	numRelaxation = numV - 1;
}

void Graph::CreateEdgeList() {
	for (int i = 0; i < numEdges; i++) {
		cout << "Enter edge " << i + 1 << " properties: Source, Destination, Weight respectively\n";
		cin >> edgeList[i].source >> edgeList[i].destination >> edgeList[i].weight;
		cout << "\n";
	}
}

void Graph::PrintVertexDistances() {

	cout << "Vertex Distance from Source Vertex\n";
	for (int i = 0; i < numVertices; i++) {
		cout << i << "\t" << distances[i] << "\n";
	}
}

void Graph::FindShortestPath() {
	for (int i = 0; i < numRelaxation; i++) {
		for (int j = 0; j < numEdges; j++) {
			int source = edgeList[j].source;
			int dest = edgeList[j].destination;
			int weight = edgeList[j].weight;

			if (distances[source] != MAX_INT) {
				if (distances[source] + weight < distances[dest]) {
					distances[dest] = distances[source] + weight;
				}
			}
		}
	}

	//check if there is a negative cycle
	bool hasNegativeCycle = false;
	for (int j = 0; j < numEdges; j++) {
		int source = edgeList[j].source;
		int dest = edgeList[j].destination;
		int weight = edgeList[j].weight;

		if (distances[source] != MAX_INT) {
			if (distances[source] + weight < distances[dest]) {
				hasNegativeCycle = true;
			}
		}
	}

	if (hasNegativeCycle) {
		cout << "This graph contains a negative edge cycle with path: \n";
	}
	else {
		cout << "This graph does not have a negative cycle.\n";
	}
}
