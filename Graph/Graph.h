#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph
{
	int V; // no of vertices
	list<int> *adj;

public:
	Graph(int V)
	{
		this->V = V;
		adj = new list<int>[V];
	}

	void addEdge(int v, int w)
	{
		adj[v].push_back(w);
	}

	bool isCyclic();

	bool isCyclicUtil(int v, vector<bool> &visited, vector<bool> &recStack);
	void BFS(int s);
	void DFS(int s);
	void DFSUtil(int s, vector<bool> &visited);
};

void Graph::BFS(int s)
{
	vector<bool> visited (V, false);

	list<int> queue;
	visited[s] = true;
	
	queue.push_back(s);

	list<int>::iterator i;

	while (!queue.empty())
	{
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		for (i = adj[s].begin(); i != adj[s].end(); i++)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}

void Graph::DFSUtil(int s, vector<bool> &visited)
{
	cout << s << " ";
	visited[s] = true;

	for (auto i = adj[s].begin(); i!=adj[s].end(); i++)
	{
		if(!visited[*i])
			DFSUtil(*i, visited);
	}
}

void Graph::DFS(int s)
{
	vector<bool> visited(V, false);
	
	DFSUtil(s, visited);
}

bool Graph::isCyclicUtil(int v, vector<bool> &visited, vector<bool> &recStack)
{
	if (visited[v] == false)
	{
		visited[v] = true;
		recStack[v] = true;

		for (auto itr = adj[v].begin(); itr != adj[v].end(); itr++)
		{
			if (1)
			{

			}
			else
			{

			}
		}
	}
}

bool Graph::isCyclic()
{
	vector<bool> visited(V, false);
	vector<bool> recStack(V, false);

	for (int i = 0; i < V; i++)
	{
		if (isCyclicUtil(i, visited, recStack));
	}

	return false;
}