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
    int numEnclaves(vector<vector<int>>& grid) {
        grid = deepClone(grid);
        
        int height = grid.size();
        int width = grid[0].size();
        
        for (int y = 0; y < height; y++) {
            floodFill(grid, y, 0, SEA);
            floodFill(grid, y, width - 1, SEA);
        }
        
        for (int x = 0; x < width; x++) {
            floodFill(grid, 0, x, SEA);
            floodFill(grid, height - 1, x, SEA);            
        }
        
        int numCells = 0;
        for (int y = 1; y < height - 1; y++) {
            for (int x = 1; x < width - 1; x++) {
                numCells += grid[y][x];
            }            
        }
       
        return numCells;
    }
    
private:
    int SEA = 0;
    vector<pair<int, int>> DIRECTIONS = {
        pair{0, -1},
        pair{0, 1},
        pair{-1, 0},
        pair{1, 0},
    };
    
    template<typename V>
    vector<V> deepClone(vector<V> old) {
        vector<V> vv;
        
        for (auto v: old) {
            vv.push_back(V(v));
        }
        
        return vv;
    }
    
    int floodFill(vector<vector<int>>& grid, int y, int x, int val) {
        int height = grid.size();
        int width = grid[0].size();
        
        bool isWithinBoundary = 0 <= y && y < height && 0 <= x && x < width;
        if (!isWithinBoundary) {
            return 0;
        }
        
        if (grid[y][x] == val) {
            return 0;
        }
        grid[y][x] = val;
        
        int count = 1;
        for (auto& [dy, dx]: DIRECTIONS) {
            int ny = y + dy;
            int nx = x + dx;
            count += floodFill(grid, ny, nx, val);
        }
        
        return count;
    }
};

class FirstSolution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        grid = deepClone(grid);
        
        int height = grid.size();
        int width = grid[0].size();
        
        for (int y = 0; y < height; y++) {
            floodFill(grid, y, 0, SEA);
            floodFill(grid, y, width - 1, SEA);
        }
        
        for (int x = 0; x < width; x++) {
            floodFill(grid, 0, x, SEA);
            floodFill(grid, height - 1, x, SEA);            
        }
        
        int numCells = 0;
        for (int y = 1; y < height - 1; y++) {
            for (int x = 1; x < width - 1; x++) {
                numCells += floodFill(grid, y, x, SEA);
            }            
        }
       
        return numCells;
    }
    
private:
    int SEA = 0;
    vector<pair<int, int>> DIRECTIONS = {
        pair{0, -1},
        pair{0, 1},
        pair{-1, 0},
        pair{1, 0},
    };
    
    template<typename V>
    vector<V> deepClone(vector<V> old) {
        vector<V> vv;
        
        for (auto v: old) {
            vv.push_back(V(v));
        }
        
        return vv;
    }
    
    int floodFill(vector<vector<int>>& grid, int y, int x, int val) {
        int height = grid.size();
        int width = grid[0].size();
        
        bool isWithinBoundary = 0 <= y && y < height && 0 <= x && x < width;
        if (!isWithinBoundary) {
            return 0;
        }
        
        if (grid[y][x] == val) {
            return 0;
        }
        grid[y][x] = val;
        
        int count = 1;
        for (auto& [dy, dx]: DIRECTIONS) {
            int ny = y + dy;
            int nx = x + dx;
            count += floodFill(grid, ny, nx, val);
        }
        
        return count;
    }
};