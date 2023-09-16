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
    int minimumEffortPath(vector<vector<int>>& heights) {
        int lo = 0;
        int hi = 1e6;
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (isPossible(heights, mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        return lo;
    }
    
    bool isPossible(vector<vector<int>>& heights, int mid) {
        int START_Y = 0;
        int START_X = 0;
        
        vector<pair<int, int>> DIRECTIONS = {
            pair{0, -1},
            pair{0, 1},
            pair{-1, 0},
            pair{1, 0},
        };
        
        int height = heights.size();
        int width = heights[0].size();
        
        vector<vector<bool>> visited;
        for (int y = 0; y < height; ++y) {
            visited.push_back(vector<bool>(width, false));
        }
        
        vector<pair<int, int>> stack = {pair{START_Y, START_X}};
        
        while (stack.size() > 0) {
            auto [y, x] = stack.back();
            stack.pop_back();
            
            if (y == height - 1 && x == width - 1) {
                return true;
            }
            
            if (visited[y][x]) {
                continue;
            }
            visited[y][x] = true;
            
            for (auto& [dy, dx]: DIRECTIONS) {
                int ny = y + dy;
                int nx = x + dx;
                
                bool isWithinBoundary = 0 <= ny && ny < height && 0 <= nx && nx < width;
                if (!isWithinBoundary) {
                    continue;
                }
                
                int diff = abs(heights[y][x] - heights[ny][nx]);
                if (diff > mid) {
                    continue;
                }
                
                stack.push_back(pair{ny, nx});
            }
        }
        return false;
    }
};