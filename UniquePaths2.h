#pragma once
#include <vector>

using namespace std;

class UniquePaths2
{
private:
    static int uniquePathsWithObstaclesHelper(vector<vector<int>>& grid, int atX, int atY) {

        if (atY >= grid.size()) return 0;
        if (atX >= grid[atY].size()) return 0;

        if (grid[atY][atX] != 0) return 0;

        if (atY == grid.size() - 1 && atX == grid[atY].size() - 1)
            return 1;

        return uniquePathsWithObstaclesHelper(grid, atX + 1, atY)
            + uniquePathsWithObstaclesHelper(grid, atX, atY + 1);

    }
public:
    static int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return uniquePathsWithObstaclesHelper(obstacleGrid, 0, 0);
    }
};

