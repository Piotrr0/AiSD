#include "WeightedGraph.h"
#include <iostream>

WeightedGraph::WeightedGraph(int n, int m, WeightedEdge edges[], bool directed) : n(n), directed(directed)
{
	adjWeightMatrix = new double* [n];
	for (int i = 0; i < n; i++)
	{
		adjWeightMatrix[i] = new double[n];
		memset(adjWeightMatrix[i], 0.f, n * sizeof(double));
	}

	for (int i = 0; i < m; i++)
	{
		int u = edges[i].s;
		int v = edges[i].t;
		adjWeightMatrix[u][v] = edges[i].w;
		if (!directed)
		{
			adjWeightMatrix[v][u] = edges[i].w;
		}
	}
}

void WeightedGraph::Dijkstra(int s)
{
	double* dist = new double[n];
	bool* visited = new bool[n]();
	for (int i = 0; i < n; i++)
	{
		dist[i] = DBL_MAX;
	}
	dist[s] = 0;

	for (int i = 0; i < n; i++)
	{
		int u = -1;
		double minDist = DBL_MAX;
		for (int j = 0; j < n; j++)
		{
			if (!visited[j] && dist[j] < minDist)
			{
				u = j;
				minDist = dist[j];
			}
		}

		if (u == -1)
		{
			break;
		}

		visited[u] = true;
		for (int v = 0; v < n; v++)
		{
			if (adjWeightMatrix[u][v] > 0 && dist[u] + adjWeightMatrix[u][v] < dist[v])
			{
				dist[v] = dist[u] + adjWeightMatrix[u][v];
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		std::cout << dist[i] << " ";
	}
	std::cout << std::endl;

	delete[] dist;
	delete[] visited;
}

void WeightedGraph::Warshall()
{
	double** dist = new double* [n];
	for (int i = 0; i < n; i++)
	{
		dist[i] = new double[n];
		for (int j = 0; j < n; j++)
		{
			dist[i][j] = adjWeightMatrix[i][j];
		}
	}

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		std::cout << "From " << i << ":\n";
		for (int j = 0; j < n; j++)
		{
			std::cout << "To " << j << ": " << dist[i][j] << std::endl;
		}
	}
}
