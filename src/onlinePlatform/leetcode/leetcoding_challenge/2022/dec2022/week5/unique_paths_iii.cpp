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
    int uniquePathsIII(vector<vector<int>>& grid) {
        height = grid.size();
        width = grid[0].size();
        answer = 0;        
        allVisitedBitMask = getAllVisitedBitMask(grid);
        
        auto [startY, startX] = getStartingCoords(grid);        
        int initVisitedBitMask = getInitVisitedBitMask(grid);
        dfs(grid, startY, startX, initVisitedBitMask);
        
        return answer;
    }
    
private:
    const int STARTING_SQUARE = 1;
    const int ENDING_SQUARE = 2;
    const int OBSTACLE = -1;
    const vector<pair<int, int>> DIRECTIONS = {
        pair{-1, 0},
        pair{1, 0},
        pair{0, -1},
        pair{0, 1}
    };
    int allVisitedBitMask;
    int height;
    int width;
    int answer;
    
    pair<int, int> getStartingCoords(vector<vector<int>>& grid) {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if (grid[y][x] == STARTING_SQUARE) {
                    return pair{y, x};
                }
            }
        } 
        throw invalid_argument("grid has no starting square");
    }
    
    void dfs(vector<vector<int>>& grid, int y, int x, int visited) {
        if (!isWithinBoundary(y, x)) {
            return;
        }
        if (grid[y][x] == OBSTACLE) {
            return;
        }
        if (isVisited(y, x, visited)) {
            return;
        }
        visited = withVisit(y, x, visited);        
        if (grid[y][x] == ENDING_SQUARE) {
            if (isAllVisited(visited)) {
                answer++;
            }
            return;
        }
        
        // for (auto& [dy, dx]: DIRECTIONS) {
        for (auto [dy, dx]: DIRECTIONS) {
            int ny = y + dy;
            int nx = x + dx;
            dfs(grid, ny, nx, visited);
        }
    }
    
    bool isWithinBoundary(int y, int x) {
        return 0 <= y && y < height && 0 <= x && x < width;
    }
    
    int withVisit(int y, int x, int visited) {
        int index = getIndex(y, x);
        int v = (int) pow(2, index);
        return v | visited;
    }
    
    bool isVisited(int y, int x, int visited) {
        int index = getIndex(y, x);
        int v = (int) pow(2, index);
        return (v & visited) > 0;
    }
    

    int getInitVisitedBitMask(vector<vector<int>>& grid) {        
        int bitmask = 0;
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if (grid[y][x] == OBSTACLE) {
                    bitmask = withVisit(y, x, bitmask);
                }
            }
        } 
        return bitmask;
    }
    
    int getAllVisitedBitMask(vector<vector<int>>& grid) {
        return -1 + (int) pow(2, width * height);
    }
    
    bool isAllVisited(int visited) {
        return allVisitedBitMask == visited;
    }
    
    int getIndex(int y, int x) {
        return y * width + x;
    }
    
};

int main() {
    Solution soln;

    vector<vector<int>> grid = {{1,0,0,0},{0,0,0,0},{0,0,2,-1}};

    cout << soln.uniquePathsIII(grid) << endl;
}