#pragma once

#include <vector>
#include <algorithm>


class RodCutting
{

private:
	static int rodCuttingHelper(std::vector<int>& rodLengths, std::vector<int>& rodPrizes, 
		int rodLength,
		int index) {

		if (index >= rodLengths.size()) return 0;
		if (rodLength <= 0) return 0;

		int profit1 = 0;

		if (rodLengths[index] <= rodLength) {
			profit1 = rodPrizes[index] + rodCuttingHelper(rodLengths, rodPrizes,
				rodLength - rodLengths[index], index);
		}

		int profit2 = rodCuttingHelper(rodLengths, rodPrizes,
			rodLength, index + 1);

		return std::max(profit1, profit2);


	}
public:
	static int rodCutting(std::vector<int> rodLengths, std::vector<int> rodPrizes, int rodLength) {
		return rodCuttingHelper(rodLengths, rodPrizes, rodLength, 0);
	}
};

