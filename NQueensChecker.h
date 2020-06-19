#pragma once

#include <vector>

using namespace std;

class NQueensChecker
{


/*
 int x - x location of queen
 int y - y location of queen
 board - chessboard as 2 dimensional vector
*/
private:
	static bool isValid(vector<vector<int>>& board, int x, int y);
public:
	static bool possible(int N);
};

