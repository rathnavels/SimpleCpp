#include <iostream>
#include <list>
#include <vector>
#include <queue>

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
	void BFS(int s, vector<int> &level);
	void RathBFS(int s);
	void DFS(int s);
	void DFSUtil(int s, vector<bool> &visited);
	void noOfElemInLevel(int level);
};

void Graph::noOfElemInLevel(int l)
{
	vector<int> level(V, 0);

	BFS(0, level);
	int count = 0;

	for (int i = 0; i < level.size(); i++)
	{
		if (level[i] == l)
		{
			count++;
		}
	}

	std::cout << "No of elem in Level is: " << count;
}

void Graph::BFS(int s, vector<int> &level)
{
	vector<bool> visited (V, false);
	list<int> queue;
	visited[s] = true;
	
	queue.push_back(s);
	level[s] = 0;

	list<int>::iterator i;

	while (!queue.empty())
	{
		s = queue.front();
		//cout << s << " ";
		queue.pop_front();
		

		for (i = adj[s].begin(); i != adj[s].end(); i++)
		{
			if (!visited[*i])
			{
				level[*i] = level[s] + 1;
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}

void Graph::RathBFS(int s)
{
	std::queue<int> Q;
	vector<bool> visited(V, false);
	
	visited[s] = true;

	Q.push(s);

	while (Q.size() != 0)
	{
		int elem = Q.front();
		Q.pop();

		std::cout << elem << " ";

		for (auto itr = adj[elem].begin(); itr != adj[elem].end(); itr++)
		{
			if (!visited[*itr])
			{
				visited[*itr] = true;
				Q.push(*itr);
			}
		}
	}
}


void Graph::DFSUtil(int s, vector<bool> &visited)
{
	cout << s << " ";
	visited[s] = true;

	for (auto i = adj[s].begin(); i != adj[s].end(); i++)
	{
		if (!visited[*i])
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
	return true;
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
