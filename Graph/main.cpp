#include <iostream>
#include "Graph.h"

using namespace std;

void runGraph101();
void runGraph102();
void runGraph103();

Graph G(12);

void main()
{

	G.addEdge(0, 1);
	G.addEdge(0, 2);
	G.addEdge(0, 3);
	G.addEdge(1, 4);
	G.addEdge(1, 5);
	G.addEdge(2, 6);
	G.addEdge(3, 7);
	G.addEdge(4, 8);
	G.addEdge(4, 9);
	G.addEdge(7, 10);
	G.addEdge(10,11);

	G.RathBFS(0);


	std::cin.get();
}