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
    double champagneTower(int poured, int query_row, int query_glass) {
        double GLASS_CAPACITY = 1.0L;
        
        vector<double> row{(double) poured};
        for (int r = 1; r <= query_row; ++r) {
            vector<double> prevRow = row;
            row = vector<double>(r + 1, 0);
            
            for (int g = 0; g < r; ++g) {
                if (prevRow[g] > 1) {
                    double spill = prevRow[g] - GLASS_CAPACITY;
                    row[g] += spill / 2.0;
                    row[g + 1] += spill / 2.0;
                }
            }
        }
            
        return min(GLASS_CAPACITY, row[query_glass]);
    }
};