#include "Graph.h"

//constructor to set graph with the correct properties
Graph::Graph(int numV, int numE, int source) {
	numVertices = numV;
	numEdges = numE;
	distances.resize(numV, MAX_INT);
	if (source < numV) {
		sourceVertex = source;
		distances[source] = 0;
	}
	else { //make sure source vetex is valid
		cout << "Source Vertex can only be between 0 and " << numV - 1 << ".\n";
		sourceVertex = 0;
		distances[0] = 0;
	}
	edgeList.resize(numE);
	
	numRelaxation = numV - 1;

	adjacencyList.resize(numVertices);
	visited.resize(numVertices, false);
}


//creates the list of edges
void Graph::CreateEdgeList() {
	for (int i = 0; i < numEdges; i++) {
		cout << "Enter edge " << i + 1 << " properties: Source, Destination, Weight respectively\n";
		int s, d, w;
		cin >> s >> d >> w;
		if (s > numVertices - 1 || d > numVertices - 1) {
			cout << "\nSource vertex and/or destination cannot be greater than " << numVertices - 1;
			cout << ".\nSetting source and destination to 0 and 1 respectively\n";
			s = 0;
			d = 1;
		}
		edgeList[i].source = s;
		edgeList[i].destination = d;
		edgeList[i].weight = w;
		AddEdge(s, d);
		cout << "\n";
	}
}

//prints the vertexes and distances if they are possible to reach
void Graph::PrintVertexDistances() {
	cout << "Vertex Distance from Source Vertex\n";
	for (int i = 0; i < numVertices; i++) {
		if(distances[i] < INT_MAX)
			cout << i << "\t" << distances[i] << "\n";
		else
			cout << i << "\t" << "Not Possible" << "\n";
	}
}

void Graph::FindShortestPath() {
	//bellman ford algorithm to find shortest path
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
				hasNegativeCycle = true; //if a distance needs to be updated, there is a negative cycle
				s = source;
				d = dest;
			}
		}
	}

	//print the cycle
	if (hasNegativeCycle) {
		cout << "This graph contains a negative edge cycle with path: ";
		cycle.push_back(d);
		FindCycle(s, d);
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

//adds edge to adjacency list
void Graph::AddEdge(int source, int destination) {
	adjacencyList[source].push_back(destination);
}

//finds the cycle and populates the cycle vector
void Graph::FindCycle(int target, int current) {
	visited[current] = true; //mark current vertex as visited to prevent infinite loop
	if (current == target) {
		cycleFound = true; //if reached beginning of cycle, mark cycle as found
	}
	else {
		for (int i = 0; i < adjacencyList[current].size(); i++) {
			if (!cycleFound && visited[adjacencyList[current][i]] == false) {
				FindCycle(target, adjacencyList[current][i]); //call function with next edge
			}
		}
	}
	if (cycleFound) {
		cycle.push_back(current); //add vertex to the cycle vector
	}
}
