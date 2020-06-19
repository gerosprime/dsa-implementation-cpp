#include "SubsetSum.h"

using namespace std;


bool SubsetSum::hasSubsetEqualtoSum(const std::vector<int>& set, int sum) {

	vector<vector<int>> computed(set.size(), vector<int>(sum + 1, -1));
	size_t startIndex = 0;
	const int currentSum = 0;
	return hasSubsetEqualtoSumHelpr(set, computed, startIndex, sum);
}


// { 1,2 }, 2
bool SubsetSum::hasSubsetEqualtoSumHelpr(const std::vector<int>& set,
	std::vector<std::vector<int>>& computed,
	size_t startIndex, int sum) {

	if (sum == 0) return true;

	if (startIndex >= set.size() || sum < 0)
		return false;

	if (computed[startIndex][sum] < 0) {
		if (hasSubsetEqualtoSumHelpr(set, computed, startIndex + 1, sum - set[startIndex])) {

			computed[startIndex][sum - set[startIndex]] = 1;
			return true;
		}
		computed[startIndex][sum] = hasSubsetEqualtoSumHelpr(set, computed,
			startIndex + 1, sum);
	}
	
	return computed[startIndex][sum];
}