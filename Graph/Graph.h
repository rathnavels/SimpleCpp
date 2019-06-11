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

	void BFS(int s);
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