#include "RGBArrayPartition.h"

#include <vector>

using namespace std;

void RGBArrayPartition::partitionRGB(std::vector<char>& rgbChars) {


	// Sort R
	//  ['G', 'B', 'R', 'R', 'B', 'R', 'G']

	// ['R', 'R', 'R', 'B', 'B', 'G', 'G']

	int lo = -1;
	int high = 0;

	// Sort R
	while (high < rgbChars.size()) {
		if (rgbChars[high] == 'R') {
			++lo;
			int temp = rgbChars[lo];
			rgbChars[lo] = rgbChars[high];
			rgbChars[high] = temp;
		}
		high++;
	}

	high = lo + 1;
	while (high < rgbChars.size()) {
		if (rgbChars[high] == 'G') {
			++lo;
			int temp = rgbChars[lo];
			rgbChars[lo] = rgbChars[high];
			rgbChars[high] = temp;
		}
		high++;
	}

	high = lo + 1;
	while (high < rgbChars.size()) {
		if (rgbChars[high] == 'B') {
			++lo;
			int temp = rgbChars[lo];
			rgbChars[lo] = rgbChars[high];
			rgbChars[high] = temp;
		}
		high++;
	}

}