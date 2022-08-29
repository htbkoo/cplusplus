#include <algorithm>
#include <vector>
#include <set>
#include <limits>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <sstream>
#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text

class Solution {
public:
    vector<pair<int, int>> DIRECTIONS = {
        pair{-1, 0},
        pair{1, 0},
        pair{0, -1},
        pair{0, 1},
    };

    int numIslands(vector<vector<char>>& grid) {
        int height = grid.size();
        int width = grid[0].size();

        vector<vector<char>> wip;
        for (auto y = 0; y < height; y++) {
            wip.push_back(vector<char>(grid[y]));
        }

        int numIslands = 0;
        for (auto y = 0; y < height; y++) {
            for (auto x = 0; x < width; x++) {
                numIslands += dfs(wip, y, x);
            }
        }

        return numIslands;
    }

    int dfs(vector<vector<char>>& grid, int y, int x) {
        int height = grid.size();
        int width = grid[0].size();

        bool isWithinBoundary = 0 <= y && y < height && 0 <= x && x < width;
        if (!isWithinBoundary) {
            return 0;
        }

        if ('0' == grid[y][x]) {
            return 0;
        }
        grid[y][x] = '0';

        for (pair<int, int> direction: DIRECTIONS) {
            int dy = direction.first;
            int dx = direction.second;

            dfs(grid, y + dy, x + dx);
        }

        return 1;
    }
};

int main() {
    Solution soln;
   
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    auto answer = soln.numIslands(grid);

    return 0;
}