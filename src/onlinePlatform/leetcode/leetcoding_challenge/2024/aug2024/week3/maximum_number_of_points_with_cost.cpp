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
    long long maxPoints(vector<vector<int>>& points) {
        int height = points.size();
        int width = points[0].size();
        
        vector<long long> prevRows(width, 0);
        
        for (int y = 0; y < height; ++y) {
            vector<long long> currRows(width, 0);
            
            long long best;
            
            best = prevRows[0];
            vector<long long> leftToRight(width, 0);
            // leftToRight[0] = prevRows[0];            
            for (int x = 0; x < width; ++x) {
                best = max(best, prevRows[x]);
                leftToRight[x] = best;
                best--;
            }
            
            best = prevRows[width - 1];
            vector<long long> rightToLeft(width, 0);
            // rightToLeft[width - 1] = rightToLeft[width - 1];
            for (int x = width - 1; x >= 0; --x) {
                best = max(best, prevRows[x]);
                rightToLeft[x] = best;
                best--;
            }
            
            for (int x = 0; x < width; ++x) {
                currRows[x] = points[y][x] + max(leftToRight[x], rightToLeft[x]);
            }
            prevRows = currRows;
        }
        
        return *max_element(begin(prevRows), end(prevRows));
    }
};
