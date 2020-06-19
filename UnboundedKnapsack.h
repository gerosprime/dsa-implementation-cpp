#pragma once

#include <vector>
#include <algorithm>

using namespace std;

class UnboundedKnapsack
{

private:
	static int maxProfitHelper(vector<int>& weights, vector<int>& profits,
							vector<vector<int>>& computed, int weight,
		int index) {

		if (weight <= 0) return 0;
		if (index >= weights.size()) return 0;

		if (computed[index][weight] < 0) {

			int profits1 = 0;
			if (weights[index] <= weight) {
				profits1 = profits[index] + maxProfitHelper(weights, profits, computed,
					weight - weights[index], index);
			}

			int profits2 = maxProfitHelper(weights, profits, computed,
				weight, index + 1);

			computed[index][weight] = max(profits1, profits2);

		}
		
		return computed[index][weight];


	}

public:
	static int maxProfit(vector<int>& weights, vector<int>& profits, int weight) {
		vector<vector<int>> computed(weights.size() + 1, vector<int>(weight + 1, -1));
		return maxProfitHelper(weights, profits, computed, weight, 0);
	}

};

