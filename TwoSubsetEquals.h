#pragma once

#include <vector>
 
class TwoSubsetEquals
{
public:
	bool canPartition(const std::vector<int>& num);
private:
	bool canPartitionHelper(const std::vector<int>& num, 
		std::vector<std::vector<int>>& computed,
		int startIndex, int targetSum);
};

