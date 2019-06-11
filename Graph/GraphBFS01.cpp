#include <iostream>
#include "Graph.h"

void runGraphBFS01()
{
	Graph G(4);

	G.addEdge(0, 1);
	G.addEdge(0, 2);
	G.addEdge(1, 2);
	G.addEdge(2, 0);
	G.addEdge(2, 3);
	G.addEdge(3, 3);

	G.BFS(2);
}