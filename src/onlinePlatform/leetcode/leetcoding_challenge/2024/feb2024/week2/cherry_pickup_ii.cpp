#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <limits>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <sstream>
#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text

const int UNINITIALIZED = -1;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int HEIGHT = grid.size();
        int WIDTH = grid[0].size();

        memo = vector<vector<vector<int>>>();
        for (int y = 0; y < HEIGHT; y++) {
            memo.push_back(vector<vector<int>>());
            for (int x = 0; x < WIDTH; x++) {
                memo.back().push_back(vector<int>(WIDTH, UNINITIALIZED));
            }
        }

        int ROBOT_1_START_X = 0;
        int ROBOT_2_START_X = WIDTH - 1;
        // TODO: what if WIDTH == 1?

        return getCherries(grid, 0, ROBOT_1_START_X, ROBOT_2_START_X) + findMax(grid, 1, ROBOT_1_START_X, ROBOT_2_START_X);
    }

private:
    vector<vector<vector<int>>> memo;

    int findMax(vector<vector<int>>& grid, int y, int x1, int x2) {
        if (y >= grid.size()) {
            return 0;
        }

        if (UNINITIALIZED == memo[y][x1][x2]) {
            memo[y][x1][x2] = 0;

            for (int dx1 =-1; dx1 <= 1; ++dx1) {
                int nx1 = x1 + dx1;
                if (nx1 < 0 or nx1 >= grid[0].size()) {
                    continue;
                }

                for (int dx2 =-1; dx2 <= 1; ++dx2) {
                    int nx2 = x2 + dx2;
                    if (nx2 < 0 or nx2 >= grid[0].size()) {
                        continue;
                    }

                    memo[y][x1][x2] = max(
                        memo[y][x1][x2],
                        getCherries(grid, y, nx1, nx2) + findMax(grid, y + 1, nx1, nx2)
                    );
                }
            }
        }

        return memo[y][x1][x2];
    }

    int getCherries(vector<vector<int>>& grid, int y, int x1, int x2) {
        int cherries = grid[y][x1];
        if (x2 != x1) {
            cherries += grid[y][x2];
        }
        return cherries;
    }
};

class WIPSolution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int HEIGHT = grid.size();
        int WIDTH = grid[0].size();

        int ROBOT_1_START_X = 0;
        int ROBOT_2_START_X = WIDTH - 1;
        // TODO: what if WIDTH == 1?

        vector<vector<int>> curr;
        for (int x = 0; x < WIDTH; x++) {
            curr.push_back(vector<int>(x, 0));
        }
        curr[ROBOT_1_START_X][ROBOT_2_START_X] = grid[0][ROBOT_1_START_X] + grid[0][ROBOT_2_START_X];

        for (int y = 1; y < HEIGHT; ++y) {
            for (int x1 = 0; x1 < WIDTH; x1++) {
                for (int x2 = 0; x2 < WIDTH; x2++) {
                    // curr.push_back(vector<int>(x, 0));
                }
            }
        }

        return 0;
    }
};

int main() {
    Solution soln;
    // vector<vector<int>> grid{{1,0,0,0,0,0,1},{2,0,0,0,0,3,0},{2,0,9,0,0,0,0},{0,3,0,5,4,0,0},{1,0,2,3,0,0,6}};
    vector<vector<int>> grid{{4,1,5,7,1},{6,0,4,6,4},{0,9,6,3,5}};

    // cout << soln.countSubstrings("aaa") << endl;
    cout << soln.cherryPickup(grid) << endl;

    return 0;
}