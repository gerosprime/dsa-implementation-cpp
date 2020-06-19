#include "Knapsack01.h"
#include <algorithm>
#include <vector>

using namespace std;

// cout << k1.solveKnapsack({3,2,3}, {2,1,1}, 2) << "\n";
int Knapsack01::solveKnapsack(const vector<int>& profits, 
							  const vector<int>& weights, int capacity) 
{
	vector<vector<int>> computed(weights.size(), vector<int>(capacity + 1, -1));
	return knapsackHelper(profits, weights, computed, 0, capacity);

}



