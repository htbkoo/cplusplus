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

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // TODO: what if grid is empty / nullptr?
        vector<int> curr = vector<int>(grid[0].begin(), grid[0].end());
        
        int height = grid.size();
        int width = grid[0].size();
        
        for (int x = 1; x < width; x++) {
            curr[x] += curr[x - 1];
        }
        
        for (int y = 1; y < height; y++) {
            curr[0] += grid[y][0];
            for (int x = 1; x < width; x++) {
                curr[x] = grid[y][x] + min(curr[x - 1], curr[x]);
            }
        }
        
        return curr[width - 1];
    }
};

class FirstSolution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // TODO: what if grid is empty / nullptr?
        vector<int> curr = vector<int>(grid[0].begin(), grid[0].end());
        
        int height = grid.size();
        int width = grid[0].size();
        
        for (int x = 1; x < width; x++) {
            curr[x] += curr[x - 1];
        }
        
        for (int y = 1; y < height; y++) {
            vector<int> prev = vector<int>(curr.begin(), curr.end());
            curr[0] = prev[0] + grid[y][0];
            for (int x = 1; x < width; x++) {
                curr[x] = grid[y][x] + min(curr[x - 1], prev[x]);
            }
        }
        
        return curr[width - 1];
    }
};
