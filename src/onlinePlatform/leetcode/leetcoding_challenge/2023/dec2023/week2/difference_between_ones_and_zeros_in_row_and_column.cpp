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
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int height = grid.size();
        int width = grid[0].size();

        vector<int> onesRow(height, 0);
        vector<int> onesCol(width, 0);
        vector<int> zerosRow(height, 0);
        vector<int> zerosCol(width, 0);

        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                if (grid[y][x] == 0) {
                    zerosRow[y]++;
                    zerosCol[x]++;
                } else if (grid[y][x] == 1) {
                    onesRow[y]++;
                    onesCol[x]++;
                }
            }
        }

        vector<vector<int>> diff;

        for (int y = 0; y < height; ++y) {
            diff.push_back(vector<int>(width, 0));
            for (int x = 0; x < width; ++x) {
                diff[y][x] = onesRow[y] + onesCol[x] - zerosRow[y] - zerosCol[x];
            }
        }

        return diff;
    }
};