#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class DecodeWays
{
private:
    

    static int numDecodings(string& s, vector<vector<int>>& computed, int numStart, int numEnd) {

        int num = strToNum(s, numStart, numEnd);

        if (!(1 <= num && num <= 26)) return 0;
        if (numEnd == s.size() - 1) {
            return 1;
        }

        if (computed[numStart][numEnd] < 0) {
            computed[numStart][numEnd] = numDecodings(s, computed, numEnd + 1, numEnd + 1)
                + numDecodings(s, computed, numStart, numEnd + 1);
        }

            
        return computed[numStart][numEnd];
    }

public:
    static int numDecodings(string s) {

        // s = "12"
        //      ^

        // s = "222"
        // 1. 2 2 2 
        // 2. 22 2
        // 3. 2 22


        // s = "2223"
        // 1. 2 2 2 3
        // 2. 22 2 3
        // 3. 22 23
        // 4. 2 22 3
        // 5. 2 2 23

        vector<vector<int>> computed(s.size(), vector<int>(s.size(), -1));

        return numDecodings(s, computed, 0, 0);
    }

    static int strToNum(string& s, int start, int end) {

   
        int res = 0;
        for (int i = start; i <= end; i++) {
            res *= 10;
            int num = s[i] - '0';
            res += num;
        }

        return res;

    }
};

