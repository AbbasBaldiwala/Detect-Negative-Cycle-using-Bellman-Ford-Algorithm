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


	adjacencyList.resize(numVertices);
	visited.resize(numVertices, false);
}

void Graph::CreateEdgeList() {
	for (int i = 0; i < numEdges; i++) {
		cout << "Enter edge " << i + 1 << " properties: Source, Destination, Weight respectively\n";
		int s, d, w;
		cin >> s >> d >> w;
		edgeList[i].source = s;
		edgeList[i].destination = d;
		edgeList[i].weight = w;
		AddEdge(s, d);
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

	int s, d;
	//check if there is a negative cycle
	bool hasNegativeCycle = false;
	for (int i = 0; i < numEdges; i++) {
		int source = edgeList[i].source;
		int dest = edgeList[i].destination;
		int weight = edgeList[i].weight;

		if (distances[source] != MAX_INT) {
			if (distances[source] + weight < distances[dest]) {
				hasNegativeCycle = true;
				//cout << source << " -> " << dest << " -> ";
				//cycle.push_back(source);
				s = source;
				d = dest;
			}
		}
	}

	if (hasNegativeCycle) {
		cout << "This graph contains a negative edge cycle with path: ";
		cycle.push_back(d);
		FindCycle(s, d, s);
		int cycleSize = cycle.size();
		for (int i = cycleSize - 1; i > 0; i--) {
			cout << cycle[i] << " -> ";
		}
		cout << cycle[0] << "\n";
	}
	else {
		cout << "This graph does not have a negative cycle.\n";
	}
}


void Graph::AddEdge(int source, int destination) {
	adjacencyList[source].push_back(destination);
}

void Graph::FindCycle(int target, int current, int prev) {
	visited[current] = true;
	if (current == target) {
		cycle.push_back(target);
		cycleFound = true;
		return;
	}
	else {
		for (int i = 0; i < adjacencyList[current].size(); i++) {
			if (!cycleFound && visited[adjacencyList[current][i]] == false) {
				FindCycle(target, adjacencyList[current][i], current);
			}
		}
	}
	if (cycleFound) {
		cycle.push_back(current);
	}
}
