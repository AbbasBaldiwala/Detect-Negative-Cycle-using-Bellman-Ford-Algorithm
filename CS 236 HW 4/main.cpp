#include "Graph.h"

int main() {
	cout << "+++ Single Source Shortest Path with Bellman-Ford +++\n\n";

	int numV, numE, source;

	cout << "Enter number of vertices: ";
	cin >> numV;
	cout << "Enter number of edges: ";
	cin >> numE;
	cout << "Enter the source vertex number: ";
	cin >> source;

	Graph G(numV, numE, source);
	G.CreateEdgeList();

	G.FindShortestPath();

	G.PrintVertexDistances();
}

//TESTS
/*
5 6 0 0 1 2 0 2 2 1 3 3 2 3 6 2 4 4 4 3 -5
*/

/*
4 5 1 0 1 1 0 3 1 1 2 -4 2 1 2 2 3 3
*/