#include <iostream>
#include "Graph.h"

using namespace std;

void runGraph101();
void runGraph102();
void runGraph103();

Graph G(4);

void main()
{

	G.addEdge(0, 1);
	G.addEdge(0, 2);
	G.addEdge(1, 3);
	G.addEdge(1, 2);
	G.addEdge(2, 0);
	G.addEdge(3, 3);




	std::cin.get();
}