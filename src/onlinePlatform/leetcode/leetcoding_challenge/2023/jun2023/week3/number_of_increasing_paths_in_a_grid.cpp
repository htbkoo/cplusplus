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
const vector<pair<int, int>> DIRECTIONS = {
    pair{-1, 0},
    pair{1, 0},
    pair{0, -1},
    pair{0, 1}
};
const int MOD = 1e9 + 7;

class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int height = grid.size();
        int width = grid[0].size();
        
        answer = 0;
        
        memo = vector<vector<int>>();
        for (int y = 0; y < height; ++y) {
            memo.push_back(vector<int>(width, UNINITIALIZED));
        }
        
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                answer = (answer + count(grid, y, x)) % MOD;
            }
        }
        
        return answer;
    }
    
private:
    vector<vector<int>> memo;
    int answer;

    int count(vector<vector<int>>& grid, int y, int x) {
        if (memo[y][x] != UNINITIALIZED) {
            return memo[y][x];
        }
        memo[y][x] = 1;  // the cell itself
        
        for (auto& [dy, dx]: DIRECTIONS) {
            int ny = y + dy;
            int nx = x + dx;
            bool isWithinBoundary = 0 <= ny && ny < grid.size() && 0 <= nx && nx < grid[0].size();
            if (!isWithinBoundary) {
                continue;
            }
            if (grid[ny][nx] <= grid[y][x]) {
                continue;
            }
            memo[y][x] = (memo[y][x] + count(grid, ny, nx)) % MOD;   
        }
        
        return memo[y][x];
    }
};