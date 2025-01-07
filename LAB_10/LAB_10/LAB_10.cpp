#include <iostream>
#include "Graph.h"

int main()
{
	int n = 6, m = 15;
	Edge directedGraph[] = { {0,4},{0,5},{1,0},{1,2},{1,4},{2,1},{2,3},{2,4},{3,2},{3,5},{4,0},{4,1},{4,3},{5,3},{5,4} };
	Graph g(n, m, directedGraph, true);
	g.bfs(0);
	g.dfs(0);
}