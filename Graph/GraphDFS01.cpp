#include<iostream>
#include<list>
using namespace std;

class GraphDFS
{
	int V;
	list<int> *adjList;

	void DFSUtil(int v, bool visited[]);

public:

	GraphDFS(int V);

	void addEdge(int v, int w);

	void DFS(int);
};

GraphDFS::GraphDFS(int V)
{
	this->V = V;
	adjList = new list<int>[V];
}

void GraphDFS::addEdge(int v, int w)
{
	adjList[v].push_back(w);
}

void GraphDFS::DFSUtil(int v, bool visited[])
{
	visited[v] = true;

	cout << v << " ";

	list<int>::iterator i;
	for (i = adjList[v].begin(); i != adjList[v].end(); i++)
	{
		if (!visited[*i])
			DFSUtil(*i, visited);
	}
}

void GraphDFS::DFS(int v)
{
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	DFSUtil(v, visited);
}

void runGraphDFS01()
{
	GraphDFS g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	g.DFS(2);
	return;
}