#include <iostream>
#include "Graph.h"
#include "WeightedGraph.h"

int main()
{
	/*
	int n = 6, m = 15;
	Edge directedGraph[] = { {0,4},{0,5},{1,0},{1,2},{1,4},{2,1},{2,3},{2,4},{3,2},{3,5},{4,0},{4,1},{4,3},{5,3},{5,4} };
	Graph g(n, m, directedGraph, true);
	g.dfs(0);
	*/

    int n = 6, m = 9;
    WeightedEdge directedGraph[] = 
    {
        {0, 1, 2.0}, {0, 2, 4.0}, {1, 2, 1.0},
        {1, 3, 7.0}, {2, 4, 3.0}, {3, 5, 1.0},
        {4, 3, 2.0}, {4, 5, 5.0}, {5, 0, 8.0}
    };

    WeightedGraph wg(n, m, directedGraph, true);
    wg.Dijkstra(0);

    return 0;
}