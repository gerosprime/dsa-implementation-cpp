#pragma once

#include <vector>
#include <algorithm>

using namespace std;
class Knapsack01
{

public:
    int solveKnapsack(const vector<int>& profits, const vector<int>& weights, int capacity);
private:
	int knapsackHelper(const vector<int>& profits,
		const vector<int>& weights, 
		vector<vector<int>>& computed, size_t startIndex, int capacity) {


		// vector<int> profits = { 1, 6, 10, 16 };
		// vector<int> weights = { 1, 2, 3, 5 };

		if (capacity <= 0) return 0;

		if (startIndex >= profits.size()) return 0;

		if (computed[startIndex][capacity] != -1) 
			return computed[startIndex][capacity];

		int totalProfit1 = 0;

		if (weights[startIndex] <= capacity) {
			totalProfit1 = profits[startIndex] + knapsackHelper(profits, weights,
				computed, startIndex + 1, capacity - weights[startIndex]);
		}

		int totalProfit2 = knapsackHelper(profits, weights,
			computed, startIndex + 1, capacity);

		computed[startIndex][capacity] = std::max(totalProfit1, totalProfit2);

		return computed[startIndex][capacity];

	}
	
	int knapsackBottomUp(const vector<int>& profits,
		const vector<int>& weights, int capacity) {

	}
};

