//Abbas Baldiwala, CS 236, Spring 2024
//Finding a Single Source Shortest Path and Detect a Negative Cycle with Bellman-Ford Algorithm

#include "Graph.h"

//vertex numbers must start at 0 and go up by 1
//for example, if there are 4 vertices, they would be 0, 1, 2, 3
//only prints one negative cycle, if two or more exist, only one will be printed

int main() {
	cout << "+++ Single Source Shortest Path with Bellman-Ford +++\n\n";

	int numV, numE, source;

	cout << "Enter number of vertices: ";
	cin >> numV;
	cout << "Enter number of edges: ";
	cin >> numE;
	cout << "Enter the source vertex number: ";
	cin >> source;

	cout << "\n";

	//create grraph object
	Graph G(numV, numE, source);

	//greate the edge list for the bellman ford algorithm to use
	G.CreateEdgeList();

	//find the shortest path to each vertex, starting from the source vertex
	G.FindShortestPath();

	//print the shortest distances
	G.PrintVertexDistances();
}

//TESTS
/*
5 6 0 0 1 2 0 2 2 1 3 3 2 3 6 2 4 4 4 3 -5
*/

/*
4 5 0 0 1 1 0 3 1 1 2 -4 2 1 2 2 3 3
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