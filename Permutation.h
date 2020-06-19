#pragma once

#include <vector>

using namespace std;

class Permutation {
public:
    static vector<vector<int>> findPermutations(const vector<int>& nums) {
        vector<vector<int>> result;

        result.push_back({ nums[0] });
        for (size_t i = 1; i < nums.size(); i++) {

            int num_element = nums[i];

            size_t result_size = result.size();
            vector<vector<int>> new_result;

            for (size_t h = 0; h < result_size; h++) {

                for (size_t j = 0; j <= i; j++) {
                    vector<int> copy_result = vector<int>(result[h]);
                    
                    copy_result.insert(copy_result.begin() + j, num_element);

                    new_result.push_back(copy_result);
                }

            }

            result = new_result;
        }
        return result;
    }
};

