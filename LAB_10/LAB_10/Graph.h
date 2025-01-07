#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

struct Edge {
	int s, t;
};

class Graph {
public:
	Graph() : n(0), matrix(nullptr), directed(false) {}
	Graph(int n, int m, Edge edges[], bool directed);
	Graph(int n, int m, bool directed);
	~Graph();

	void bfs(int s);
	void dfs(int s);

private:
	void dfs_helper(int s, int* visited);

	int** matrix;
	int n;
	bool directed;
};
