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

const int LAND = 1;
const int WATER = 0;
const vector<pair<int, int>> DIRECTIONS{
    pair{-1, 0},
    pair{1, 0},
    pair{0, -1},
    pair{0, 1}
};

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int height = grid.size();
        int width = grid[0].size();
                
        vector<vector<bool>> visited;
        for (int y = 0; y < height; ++y) {
            visited.push_back(vector<bool>(width, false));
        }

        queue<pair<int, int>> waters;
        
        auto firstLandCoors = findFirstLandCoors(grid);
        queue<pair<int, int>> q({firstLandCoors});
        while (q.size() > 0) {
            auto [y, x] = q.front();
            q.pop();

            bool isWithinBoundary = 0 <= y && y < height && 0 <= x && x < width;
            if (!isWithinBoundary) {
                continue;
            }            
        
            if (grid[y][x] == WATER) {
                waters.push(pair{y, x});
                continue;
            }
            
            if (visited[y][x]) {
                continue;
            }
            visited[y][x] = true;
            
            for (auto& [dy, dx]: DIRECTIONS) {
                int ny = y + dy;
                int nx = x + dx;
                q.push(pair{ny, nx});
            }
        }
        
        int answer = 0;
        while (waters.size() > 0) {
            int count = waters.size();
            for (int i = 0; i < count; ++i) {
                auto [y, x] = waters.front();
                waters.pop();

                bool isWithinBoundary = 0 <= y && y < height && 0 <= x && x < width;
                if (!isWithinBoundary) {
                    continue;
                }
                
                if (visited[y][x]) {
                    continue;
                }
                visited[y][x] = true;

                if (grid[y][x] == LAND) {
                    return answer;
                }

                for (auto& [dy, dx]: DIRECTIONS) {
                    int ny = y + dy;
                    int nx = x + dx;
                    waters.push(pair{ny, nx});
                }
            }
            
            answer++;
        }

        // return -1;   
        throw invalid_argument("unable to connect the islands");
    }
    
private:
    pair<int, int> findFirstLandCoors(vector<vector<int>>& grid) {
        int height = grid.size();
        int width = grid[0].size();
        
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                if (grid[y][x] == LAND) {
                    return pair{y, x};
                }
            }
        }

        throw invalid_argument("grid has no land");
    }
};

int main() {
    Solution soln;

    // vector<vector<int>> grid = {{0,1},{1,0}};
    vector<vector<int>> grid = {{0,1,0},{0,0,0},{0,0,1}};

    cout << soln.shortestBridge(grid) << endl;

    return 0;
}