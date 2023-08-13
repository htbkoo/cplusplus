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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int height = obstacleGrid.size();
        int width = obstacleGrid[0].size();
        
        vector<vector<int>> counts;
        for (int y = 0; y < height; ++y) {
            counts.push_back(vector<int>(width, 0));
        }
        
        for (int x = 0; x < width; ++x) {
            if (obstacleGrid[0][x] == 0) {
                counts[0][x] = 1;
            } else {
                break;
            }
        }
        
        for (int y = 0; y < height; ++y) {
            if (obstacleGrid[y][0] == 0) {
                counts[y][0] = 1;
            } else {
                break;
            }
        }
        
        for (int y = 1; y < height; ++y) {
            for (int x = 1; x < width; ++x) {
                if (obstacleGrid[y][x] == 0) {
                    counts[y][x] = counts[y][x - 1] + counts[y - 1][x];
                }
            }
        }
        
        return counts[height - 1][width - 1];
    }
};
