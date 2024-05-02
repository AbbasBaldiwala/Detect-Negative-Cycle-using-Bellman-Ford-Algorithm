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

/*
4 5 0 0 1 1 1 2 1 2 0 -4 2 3 1 0 3 1
*/

/*
10 11 0 9 4 -10 4 9 1 0 1 1 1 2 1 2 5 1 5 0 -10 1 3 1 1 4 1 2 6 1 3 8 1 2 7 1 
*/

/*
4 5 0 0 1 4 0 3 5 3 2 3 2 1 -10 1 3 5
*/

/*
7 10 0 0 1 6 0 2 5 0 3 5 1 4 -1 2 1 -2 3 2 -2 2 4 1 3 5 -1 4 6 3 5 6 3
*/