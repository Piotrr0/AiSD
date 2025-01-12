#pragma once
struct WeightedEdge
{
	int s, t;
	double w;
};

class WeightedGraph
{
public:
	WeightedGraph(int n, int m, WeightedEdge edges[], bool directed);
	void Dijkstra(int s);
	void Warshall();

private:
	double** adjWeightMatrix;
	int n;
	bool directed;
};

