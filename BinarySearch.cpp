#include "BinarySearch.h"

int BinarySearch::binary_search(std::vector<int>& nums, int num) {
	int start = 0;
	int end = nums.size() - 1;

	while (start <= end) {

		int mid = start + (end - start) / 2;

		int val = nums[mid];

		if (val == num) return mid;
		else if (val < num) start = mid + 1;
		else end = mid - 1;

	}

	return -1;
}