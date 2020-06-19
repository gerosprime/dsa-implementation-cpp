#pragma once

#include <vector>


template<typename G, int N>
struct Buffer {
	using value_type = G;
	constexpr int size() {
		return N;
	}
	G g[N];

};

class SubsetSum
{
public:
	bool hasSubsetEqualtoSum(const std::vector<int>& set, int sum);
private:
	bool hasSubsetEqualtoSumHelpr(const std::vector<int>& set, 
		std::vector<std::vector<int>>& computed,
		size_t startIndex, int sum);
};

