#include "TopologicalSort.h"
#include <unordered_map>
#include <algorithm>
#include <queue>

vector<int> TopologicalSort::sort(int vertices, 
	vector<vector<int>>& edges) {

	vector<int> sorted;

	unordered_map<int, int> inDegrees;
	unordered_map<int, vector<int>> edgesMap;

	for (int i = 0; i <= vertices; i++) {

		inDegrees[i] = 0;
		edgesMap[i] = vector<int>();
	}

	for (int i = 0; i < edges.size(); i++) {
		int parent = edges[i][0];
		int child = edges[i][1];

		edgesMap[parent].push_back(child);
		inDegrees[child]++;
	}


	queue<int> sources;

	for (auto& pair : inDegrees) {
		if (pair.second == 0)
			sources.push(pair.first);
	}

	while (!sources.empty()) {
		int top = sources.front();
		sources.pop();
		sorted.push_back(top);

		vector<int> destination = edgesMap[top];
		for (int& n : destination) {
			inDegrees[n]--;
			if (inDegrees[n] == 0) {
				inDegrees.erase(n);
				sources.push(n);
			}

		}

	}

	if (!sources.empty()) return {};

	return sorted;
}