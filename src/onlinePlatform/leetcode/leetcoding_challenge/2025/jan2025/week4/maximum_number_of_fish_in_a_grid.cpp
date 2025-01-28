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

vector<pair<int, int>> DIRECTIONS{
    pair{-1, 0},
    pair{1, 0},
    pair{0, -1},
    pair{0, 1},
};

// improved my solution after reading discussion
// reference: https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/editorial/comments/2827279
class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        // TODO: Clone grid to avoid mutating input
        
        int HEIGHT = grid.size();
        int WIDTH = grid[0].size();
        
        int answer = 0;
        for (int y = 0; y < HEIGHT; ++y) {
            for (int x = 0; x < WIDTH; ++x) {
                answer = max(answer, dfs(grid, y, x));
            }
        }
        
        for (int y = 0; y < HEIGHT; ++y) {
            for (int x = 0; x < WIDTH; ++x) {
                grid[y][x] = -grid[y][x];
            }
        }
        
        return answer;
    }
    
private:
    int dfs(vector<vector<int>>& grid, int y, int x) {
        int HEIGHT = grid.size();
        int WIDTH = grid[0].size();
        bool isWithinBoundary = 0 <= y && y < HEIGHT && 0 <= x && x < WIDTH;
        if (!isWithinBoundary) {
            return 0;
        }
        bool isWater = grid[y][x] > 0;
        if (!isWater) {
            return 0;
        }
        int fish = grid[y][x];
        grid[y][x] = -grid[y][x];
        
        for (auto& [dy, dx]: DIRECTIONS) {
            fish += dfs(grid, y + dy, x + dx);
        }
        
        return fish;
    }    
};

class FirstSolution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        // TODO: Clone grid to avoid mutating input
        
        int HEIGHT = grid.size();
        int WIDTH = grid[0].size();
        
        int answer = 0;
        for (int y = 0; y < HEIGHT; ++y) {
            for (int x = 0; x < WIDTH; ++x) {
                answer = max(answer, dfs(grid, y, x));
            }
        }
        
        return answer;
    }
    
private:
    int dfs(vector<vector<int>>& grid, int y, int x) {
        int HEIGHT = grid.size();
        int WIDTH = grid[0].size();
        bool isWithinBoundary = 0 <= y && y < HEIGHT && 0 <= x && x < WIDTH;
        if (!isWithinBoundary) {
            return 0;
        }
        bool isWater = grid[y][x] > 0;
        if (!isWater) {
            return 0;
        }
        int fish = grid[y][x];
        grid[y][x] = 0;
        
        for (auto& [dy, dx]: DIRECTIONS) {
            fish += dfs(grid, y + dy, x + dx);
        }
        
        return fish;
    }    
};