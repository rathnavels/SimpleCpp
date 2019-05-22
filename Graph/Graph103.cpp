#include <iostream>
#include <vector>
using namespace std;

struct Edge
{
	int src, dest;
};

class Graph103
{
public:
	vector<vector<int>> adjList;

	Graph103(vector<Edge> &edges, int N)
	{
		adjList.resize(N);
		for (auto &edge : edges)
		{
			adjList[edge.src].push_back(edge.dest);
			adjList[edge.dest].push_back(edge.src);
		}
	}
};

void printGraph(Graph103 &graph, int N)
{		
	for (auto row : graph.adjList)
	{
		for(auto i : row)
			cout << "-->" << i;

		cout << endl;
	}
}

void runGraph103()
{
	vector<Edge> edges = 
	{
		{ 0,1 },{ 1,2 },{ 2,0 },{ 2,1 },
		{ 3,2 },{ 4,5 },{ 5,4 }
	};
	Graph103 graph(edges, 6);
	printGraph(graph, 6);
}