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
    int* visited = new int[n]();
    std::queue<int> queue;

    queue.push(s);
    visited[s] = true;

    while (!queue.empty())
    {
        int v = queue.front();
        queue.pop();

        std::cout << v << " ";

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && matrix[v][i])
            {
                queue.push(i);
                visited[i] = true;
            }
        }
    }

    delete[] visited;
}


void Graph::dfs(int s)
{
	int* visited = new int[n]();
	dfs_helper(s, visited);
	delete[] visited;
}

void Graph::dfs_helper(int s, int* visited)
{
	visited[s] = 1;
	std::cout << s << " ";
	for (int i = 0; i < n; i++)
	{
		if (!visited[i] && matrix[s][i] == 1)
		{
			dfs_helper(i, visited);
		}
	}
}
