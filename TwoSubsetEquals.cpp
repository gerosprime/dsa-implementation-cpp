#include "TwoSubsetEquals.h"
#include <vector>
#include <string>
#include <map>

#include <complex>

using namespace std;

bool TwoSubsetEquals::canPartition(const vector<int>& num) {

	int sum = 0;
	for (int i = 0; i < num.size(); i++) {
		sum += num[i];
	}


	vector<vector<int>> computed(num.size(), vector<int>(sum, -1));

	if (num.size() <= 1 || sum % 2 != 0) return false;

	return canPartitionHelper(num, computed, 0, sum / 2);
}


// { 1,2,3,4 }, t = 5
bool TwoSubsetEquals::canPartitionHelper(const vector<int>& num, 
				vector<vector<int>>& computed,
				int startIndex, int targetSum) {

	if (targetSum == 0) return true;

	if (targetSum < 0 || startIndex >= num.size()) return false;


	if (computed[startIndex][targetSum] < 0) {

		if (canPartitionHelper(num, computed, startIndex + 1, targetSum - num[startIndex])) {
			computed[startIndex][targetSum] = 1;
			return true;
		}
		
		computed[startIndex][targetSum] =
			canPartitionHelper(num, computed, startIndex + 1, targetSum);
		
	}
	
	return computed[startIndex][targetSum] == 1;
	

}


bool canPartitionHelperBU(const vector<int>& num) {

	int sum = 0;
	for (int i = 0; i < num.size(); i++) {
		sum += num[i];
	}

	vector<vector<int>> computed(num.size(), vector<int>(sum, -1));

	for (int i = 0; i < computed.size(); i++) {
		computed[i][0] = 1;
	}

	return false;

}