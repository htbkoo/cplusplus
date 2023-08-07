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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) {
            return false;
        }
        
        int height = matrix.size();
        int width = matrix[0].size();
        
        int x = width - 1;
        int y = 0;
        
        while (x >= 0 && y < height) {
            int val = matrix[y][x];
            
            if (val > target) {
                x -= 1;
            } else if (val < target) {
                y += 1;
            } else {
                return true;
            }
        }
        
        return false;
    }
};