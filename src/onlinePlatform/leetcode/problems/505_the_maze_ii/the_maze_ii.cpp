#include <algorithm>
#include <vector>
#include <set>
#include <limits>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <sstream>
#include <queue>
#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text

// reference: https://stackoverflow.com/a/15161034
struct pair_hash {
    inline size_t operator()(const pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {              
        vector<pair<int, int>> DIRECTIONS = {
            pair{-1, 0},
            pair{1, 0},
            pair{0, -1},
            pair{0, 1},
        };
        int WALL = 1;

        int height = maze.size();
        int width = maze[0].size();

        int startY = start[0];
        int startX = start[1];
        int destY = destination[0];
        int destX = destination[1];

        unordered_set<pair<int, int>, pair_hash> visited;
        
        priority_queue<pair<int, pair<int, int>>> q;
        q.push(pair{0, pair{startY, startX}});
        
        while (q.size() > 0) {
            pair<int, pair<int, int>> t = q.top();
            q.pop();
            int dist = t.first;
            pair<int, int> pos = t.second;
            int y = pos.first;
            int x = pos.second;

            int isReachedDest = y == destY && x == destX;
            if (isReachedDest) {
                return -dist;
            }

            if (visited.count(pos)) {
                continue;
            }
            visited.insert(pos);

            for (auto direction: DIRECTIONS) {
                int dy = direction.first;
                int dx = direction.second;

                int newDist = dist;
                int newY = y;
                int newX = x;

                while (0 <= newY && newY < height && 0 <= newX && newX < width && maze[newY][newX] != WALL) {                    
                    newDist--;
                    newY += dy;
                    newX += dx;
                }
                newDist++;            
                newY -= dy;
                newX -= dx;
                q.push(pair{newDist, pair{newY, newX}});
            }
        }

        return -1;
    }
};

int main() {
    Solution soln;

    vector<vector<int>> maze = {{0,0,1,0,0},{0,0,0,0,0},{0,0,0,1,0},{1,1,0,1,1},{0,0,0,0,0}};
    vector<int> start = {0,4}, destination = {3,2};

    // vector<vector<char>> grid = {
    //     {'1','1','1','1','0'},
    //     {'1','1','0','1','0'},
    //     {'1','1','0','0','0'},
    //     {'0','0','0','0','0'}
    // };
    auto answer = soln.shortestDistance(maze, start, destination);

    return 0;
}