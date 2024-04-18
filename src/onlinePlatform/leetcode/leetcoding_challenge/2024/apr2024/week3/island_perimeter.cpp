#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <limits>
#include <map>
#include <set>
#include <unordered_map>
#include <iterator>
#include <sstream>
#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text

const int WATER = 0;

const vector<pair<int, int>> DIRECTIONS{
    pair{-1, 0},
    pair{1, 0},
    pair{0, -1},
    pair{0, 1}
};

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int HEIGHT = grid.size();
        int WIDTH = grid[0].size();

        int answer = 0;
        
        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                if (grid[y][x] == WATER) {
                    continue;
                }
                for (auto &[dy, dx]: DIRECTIONS) {
                    int ny = y + dy;
                    int nx = x + dx;
                    if (isWater(grid, ny, nx)) {
                        answer++;
                    }
                }
            }
        } 

        return answer;
    }
    
private:
    bool isWithinBoundary(vector<vector<int>>& grid, int y, int x) {
        int HEIGHT = grid.size();
        int WIDTH = grid[0].size();

        return 0 <= y && y < HEIGHT && 0 <= x && x < WIDTH;
    }

    bool isWater(vector<vector<int>>& grid, int y, int x) {
        return !isWithinBoundary(grid, y, x) || grid[y][x] == WATER;
    }
};

int main() {
    Solution soln;

    vector<vector<int>> grid{{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};

    cout << soln.islandPerimeter(grid) << endl;
    return 0;
}

/*
class NotWorkingSolution2 {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        set<pair<int, int>> visitedCell = set<pair<int, int>>();
        set<tuple<int, int, int, int>> borders = set<tuple<int, int, int, int>>();

        int HEIGHT = grid.size();
        int WIDTH = grid[0].size();

        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                dfs(grid, y, x);
            }
        } 

        return borders.size();
    }
    
private:
    set<pair<int, int>> visitedCell;
    set<tuple<int, int, int, int>> borders;

    void dfs(vector<vector<int>>& grid, int y, int x) {
        if (!isWithinBoundary(grid, y, x)) {
            return;
        }

        if (visitedCell.count(pair{y, x}) > 0) {
            return;
        }
        visitedCell.insert(pair{y, x});

        for (auto [dy, dx]: DIRECTIONS) {
            int ny = y + dy;
            int nx = x + dx;
            if (shouldAdd(grid, y, x, ny, nx)) {
                borders.insert(tuple{y, x, ny, nx});
            }
            dfs(grid, ny, nx);
        }
        return;
    }

    bool isWithinBoundary(vector<vector<int>>& grid, int y, int x) {
        int HEIGHT = grid.size();
        int WIDTH = grid[0].size();

        return 0 <= y && y < HEIGHT && 0 <= x && x < WIDTH;
    }

    bool isWater(vector<vector<int>>& grid, int y, int x) {
        return !isWithinBoundary(grid, y, x) && grid[y][x] == WATER;
    }

    bool isBorder(vector<vector<int>>& grid, int yFrom, int xFrom, int yTo, int xTo) {
        return isWater(grid, yFrom, xFrom) != isWater(grid, yTo, xTo);
    }

    bool shouldAdd(vector<vector<int>>& grid, int yFrom, int xFrom, int yTo, int xTo) {
        if (borders.count(tuple{yFrom, xFrom, yTo, xTo}) > 0 || borders.count(tuple{yTo, xTo, yFrom, xFrom}) > 0) {
            return false;
        }
        return isBorder(grid, yFrom, xFrom, yTo, xTo);
    }
};

class NotWorkingSolution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        unordered_set<pair<int, int>> visitedCell = unordered_set<pair<int, int>>();
        unordered_set<tuple<int, int, int, int>> borders = unordered_set<tuple<int, int, int, int>>();

        int HEIGHT = grid.size();
        int WIDTH = grid[0].size();

        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                dfs(grid, y, x);
            }
        } 

        return borders.size();
    }
    
private:
    unordered_set<pair<int, int>> visitedCell;
    unordered_set<tuple<int, int, int, int>> borders;

    int dfs(vector<vector<int>>& grid, int y, int x) {
        if (!isWithinBoundary(grid, y, x)) {
            return 0;
        }

        if (visitedCell.count(pair{y, x}) > 0) {
            return 0;
        }
        visitedCell.insert(pair{y, x});

        for (auto [dy, dx]: DIRECTIONS) {
            int ny = y + dy;
            int nx = x + dx;
            if (shouldAdd(grid, y, x, ny, nx)) {
                borders.insert(tuple{y, x, ny, nx});
            }
            dfs(grid, ny, nx);
        }
    }

    bool isWithinBoundary(vector<vector<int>>& grid, int y, int x) {
        int HEIGHT = grid.size();
        int WIDTH = grid[0].size();

        return 0 <= y && y < HEIGHT && 0 <= x && x < WIDTH;
    }

    bool isWater(vector<vector<int>>& grid, int y, int x) {
        return !isWithinBoundary(grid, y, x) || grid[y][x] == WATER;
    }

    bool isBorder(vector<vector<int>>& grid, int yFrom, int xFrom, int yTo, int xTo) {
        return isWater(grid, yFrom, xFrom) != isWater(grid, yTo, xTo);
    }

    bool shouldAdd(vector<vector<int>>& grid, int yFrom, int xFrom, int yTo, int xTo) {
        if (borders.count(tuple{yFrom, xFrom, yTo, xTo}) > 0 || borders.count(tuple{yTo, xTo, yFrom, xFrom}) > 0) {
            return false;
        }
        return isBorder(grid, yFrom, xFrom, yTo, xTo);
    }
};
*/