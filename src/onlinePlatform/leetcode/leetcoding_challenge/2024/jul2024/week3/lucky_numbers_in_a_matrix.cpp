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
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        auto height = matrix.size();
        auto width = matrix[0].size();
        
        vector<int> rowsMax(height, numeric_limits<int>::max());
        vector<int> colsMax(width,  numeric_limits<int>::min());
        
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                rowsMax[y] = min(rowsMax[y], matrix[y][x]);
                colsMax[x] = max(colsMax[x], matrix[y][x]);
            }
        }
        
        vector<int> answer;        
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                if (matrix[y][x] == rowsMax[y] && matrix[y][x] == colsMax[x]) {
                    answer.push_back(matrix[y][x]);
                }
            }
        }
        
        return answer;
    }
};
