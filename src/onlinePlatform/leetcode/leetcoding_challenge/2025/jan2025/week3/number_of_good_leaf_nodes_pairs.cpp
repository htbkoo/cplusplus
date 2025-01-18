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
    int minCost(vector<vector<int>>& grid) {
        auto HEIGHT = grid.size();
        // TODO: validate HEIGHT > 0
        auto WIDTH = grid[0].size();

        auto START_Y = 0;
        auto START_X = 0;
        auto START_COST = 0;
        auto TARGET_Y = HEIGHT - 1;
        auto TARGET_X = WIDTH - 1;
        
        auto UNINITIALZED = numeric_limits<int>::max() / 2;
        
        vector<pair<int, int>> DIRECTIONS = {
            {0, 1}, // right
            {0, -1}, // left
            {1, 0}, // low
            {-1, 0}, // up
        };

        vector<vector<int>> best(HEIGHT, vector<int>(WIDTH, UNINITIALZED));
        best[START_Y][START_X] = START_COST;
        
        priority_queue<tuple<int, int, int>> pq;
        pq.push(tuple(-START_COST, START_Y, START_X));

        while (pq.size() > 0) {
            auto [negCost, y, x] = pq.top();
            pq.pop();
            auto cost = -negCost;
            if (y == TARGET_Y && x == TARGET_X) {
                return cost;
            }

            for (auto i = 0; i < DIRECTIONS.size(); ++i) {
                auto gridValue = i + 1;
                auto [dy, dx] = DIRECTIONS[i];
                auto ny = y + dy;
                auto nx = x + dx;
                bool isWithinBoundary = 0 <= ny && ny < HEIGHT && 0 <= nx && nx < WIDTH;
                if (!isWithinBoundary) {
                    continue;
                }
                auto nCost = gridValue == grid[y][x] ? cost : (cost + 1);
                if (nCost >= best[ny][nx]) {
                    continue;
                }
                best[ny][nx] = nCost;
                pq.push(tuple(-nCost, ny, nx));
            }
        }
        
        // TODO: or throw error here - programing error
        // return best[HEIGHT - 1][WIDTH - 1];
        return -1;
    }
};