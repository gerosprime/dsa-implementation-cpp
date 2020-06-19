#pragma once

#include<vector>
#include<stack>
#include <iostream>

using namespace std;

class NumIslands
{

private:
    vector<pair<int, int>> adjacentLands(vector<vector<char>>& grid,
        int x, int y) {
        vector<pair<int, int>> result;

        int left = x - 1;
        int right = x + 1;
        int up = y - 1;
        int down = y + 1;

        if (left >= 0) result.push_back({ left, y });
        if (right < grid[y].size()) result.push_back({ right, y });
        if (up >= 0) result.push_back({ x, up });
        if (down < grid.size()) result.push_back({ x, down });


        return result;
    }
public:
    int numIslands(vector<vector<char>>& grid) {

        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), -1));

        int islands = 0;


        stack<pair<int, int>> stackTraverse;
        for (int y = 0; y < grid.size(); y++) {


            for (int x = 0; x < grid[y].size(); x++) {

                bool hasVisited = visited[y][x] > -1;
                bool isLandAndNotVisited = grid[y][x] == '1' && !hasVisited;

                if (isLandAndNotVisited) {
                    stackTraverse.push({ x, y });

                    while (!stackTraverse.empty()) {

                        pair<int, int> top = stackTraverse.top();
                        visited[top.second][top.first] = 1;
                        stackTraverse.pop();

                        vector<pair<int, int>> adjs = adjacentLands(grid, top.first, top.second);

                        for (auto adjacent : adjs) {

                            char terrain = grid[adjacent.second][adjacent.first];
                            bool terrainLand = terrain == '1';
                            bool hasVisited = visited[adjacent.second][adjacent.first] > -1;
                            if (terrainLand && !hasVisited) {
                                cout << "Pushing (" + adjacent.first << ", " << adjacent.second << ")" << "\n";
                                stackTraverse.push(adjacent);
                            }
                            else if (!terrainLand) {
                                visited[adjacent.second][adjacent.first] = 0;
                            }
                                
                        }
                    }

                    islands++;

                }

            }
        }

        return islands;
    }

};

