#pragma once

#include<vector>
#include "Edge.h"

using namespace std;
class AdjacencyList
{
private:
	vector<int> vertices;
	vector<vector<Edge*>> edges;
public:
	AdjacencyList(int vertices);
	~AdjacencyList();
	void addEdge(int vertice, int targetVertice, bool direct);
};

