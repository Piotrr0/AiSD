#include "Graph.h"
#include <vector>
#include <queue>
#include <iostream>

Graph::Graph(int n, int m, Edge edges[], bool directed) : n(n), directed(directed)
{
	matrix = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
		memset(matrix[i], 0, n * sizeof(int));
	}

	for (int i = 0; i < m; i++) 
	{
		int u = edges[i].s;
		int v = edges[i].t;
		matrix[u][v] = 1;
		if (!directed) 
		{
			matrix[v][u] = 1;
		}
	}
}

Graph::Graph(int n, int m, bool directed) : n(n), directed(directed)
{
	matrix = new int* [n];
	for (int i = 0; i < n; i++) 
	{
		matrix[i] = new int[n];
		memset(matrix[i], 0, n * sizeof(int));
	}
}

Graph::~Graph()
{
	for (int i = 0; i < n; i++) 
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

void Graph::bfs(int s)
{
	std::vector<bool> visited(n, false);
	std::queue<int> q;

	visited[s] = true;
	q.push(s);

	while (!q.empty()) 
	{
		int u = q.front();
		q.pop();

		std::cout << u << " ";

		for (int v = 0; v < n; v++) 
		{
			if (matrix[u][v] == 1 && !visited[v]) 
			{
				visited[v] = true;
				q.push(v);
			}
		}
	}
	std::cout << std::endl;
}

void Graph::dfs(int s)
{
	int* visited = new int[n];
	memset(visited, 0, n * sizeof(int));
	dfs_helper(s, visited);
	std::cout << std::endl;
	delete[] visited;
}

void Graph::dfs_helper(int s, int* visited)
{
	visited[s] = 1;
	std::cout << s << " ";

	for (int v = 0; v < n; v++) 
	{
		if (matrix[s][v] == 1 && !visited[v]) 
		{
			dfs_helper(v, visited);
		}
	}
}
