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
    int maxDistance(vector<vector<int>>& grid) {
        // assume we can mutate grid
        // TODO: make a copy of grid first
        
        vector<vector<int>> dists(grid);
        
        int LAND = 1;
        vector<pair<int, int>> DIRECTIONS = {
            pair{-1, 0},
            pair{1, 0},
            pair{0, -1},
            pair{0, 1}
        };
        
        int height = dists.size();
        int width = dists[0].size();
        
        queue<pair<int, int>> q;
                
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if (grid[y][x] == LAND) {
                    q.push(pair{y, x});
                }
            }
        }
        
        int NO_LAND_NOR_WATER = -1;
        if (q.size() == 0 || q.size() == width * height) {
            return NO_LAND_NOR_WATER;
        }
        
        int answer = 0;
        while (q.size() > 0) {
            auto [y, x] = q.front();
            q.pop();
                        
            for (auto &[dy, dx]: DIRECTIONS) {
                int ny = y + dy, nx = x + dx;
                bool isWithinBoundary = 0 <= ny && ny < height && 0 <= nx && nx < width;
                if (!isWithinBoundary) {
                    continue;
                }
                if (dists[ny][nx] != 0) {
                    continue;
                }
                dists[ny][nx] = dists[y][x] + 1;
                answer = max(answer, dists[ny][nx]);
                
                q.push(pair{ny, nx});
            }
            dists[y][x] = -1;
        }
        
        return answer - 1;
    }
};

int main() {
    Solution soln;
    vector<vector<int>> grid = {{1,0,1},{0,0,0},{1,0,1}};
    cout << soln.maxDistance(grid) << endl;

    return 0;
}