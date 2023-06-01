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
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        const vector<pair<int, int>> DIRECTIONS = {
            pair{-1, -1},
            pair{-1, 0},
            pair{-1, 1},
            pair{0, -1},
            pair{0, 1},
            pair{1, -1},
            pair{1, 0},
            pair{1, 1}
        };
        
        // TODO: verify input, e.g. grid is not nullptr, grid is not empty, grid is rectangular, grid only have 0 and 1
        int height = grid.size();
        int width = grid[0].size();
        
        int BEGIN_Y = 0;
        int BEGIN_X = 0;
        int END_Y = height - 1;
        int END_X = width - 1;
        
        int CLEAR = 0;
        int NO_CLEAR_PATH = -1;
        
//         if (grid[BEGIN_Y][BEGIN_X] != CLEAR) {
//             return NO_CLEAR_PATH;
//         }
            
        vector<vector<bool>> visited;
        for (int y = 0; y < height; ++y) {
            visited.push_back(vector<bool>(width, false));
        }

        queue<pair<int, int>> q;
        q.push(pair{BEGIN_Y, BEGIN_X});
        int pathSize = 1;
        
        while (q.size() > 0) {
            int count = q.size();
            
            for (int i = 0; i < count; i++) {
                auto [y, x] = q.front();
                q.pop();
                
                bool isWithinBoundary = 0 <= y && y < height && 0 <= x && x < width;
                if (!isWithinBoundary) {
                    continue;
                }
                
                if (visited[y][x]) {
                    continue;
                }
                visited[y][x] = true;
                
                if (grid[y][x] != CLEAR) {
                    continue;
                }
                
                if (y == END_Y && x == END_X) {
                    return pathSize;
                }
                
                for (auto& [dy, dx]: DIRECTIONS) {
                    int ny = y + dy;
                    int nx = x + dx;
                    q.push(pair{ny, nx});
                }
                
            }
            
            pathSize++;
        }
        
        return NO_CLEAR_PATH;
    }
};