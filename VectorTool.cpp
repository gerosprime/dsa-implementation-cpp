
#include <iostream>
#include<vector>
#include "VectorTool.h"

using namespace std;

template <typename T>
void VectorTool::printContent(vector<T>& arr) {

	std::cout << "[";
	for (size_t i = 0; i < arr.size(); i++) {

		std::cout << arr[i];
		if (i + 1 < arr.size())
			std::cout << ", ";
	}
	std::cout << "]";


}