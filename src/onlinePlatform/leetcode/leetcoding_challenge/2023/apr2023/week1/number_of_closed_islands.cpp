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
    int closedIsland(vector<vector<int>>& grid) {
        int height = grid.size();
        int width = grid[0].size();
        
        visited = unordered_map<int, unordered_map<int, bool>>();
        
        
        int answer = 0;
        
        for (int y = 1; y < height - 1; y++) {
            for (int x = 1; x < width - 1; x++) {
                if (!visited[y][x] && grid[y][x] == LAND) {
                    if (isClosedIsland(grid, y, x)) {
                        answer++;
                    }
                }
            }
        }
        
        return answer;
    }
    
private:
    vector<pair<int, int>> DIRECTIONS = {
        pair{-1, 0},
        pair{1, 0},
        pair{0, -1},
        pair{0, 1}
    };
    int LAND = 0;
    int WATER = 1;
    unordered_map<int, unordered_map<int, bool>> visited;
    
    bool isClosedIsland(vector<vector<int>>& grid, int y, int x) {
        int height = grid.size();
        int width = grid[0].size();
        
        if (visited[y][x]) {
            return true;
        }
        visited[y][x] = true;
        
        int cell = grid[y][x];
        if (cell == WATER) {
            return true;
        }
        
        bool isBoundary = y == 0 || y == height - 1 || x == 0 || x == width - 1;
        if (isBoundary) {
            return false;
        }
        
        bool isClosed = true;
        for (auto [dy, dx]: DIRECTIONS) {
            int ny = y + dy;
            int nx = x + dx;
            if (!isClosedIsland(grid, ny, nx)) {
                isClosed = false;
            }
        }
        
        return isClosed;
    }
};
