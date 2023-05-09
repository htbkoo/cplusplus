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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // TODO: validate input
        vector<int> answer;
    
        int HEIGHT = matrix.size();
        if (HEIGHT == 0) {
            return answer;
        }
        // assume matrix is rectangular
        int WIDTH = matrix[0].size();
        if (WIDTH == 0) {
            return answer;
        }
    
        int layer = 0;
        while (true) {
            int top = layer;
            int bottom = HEIGHT - 1 - layer;
            if (top > bottom) {
                break;
            }
            int left = layer;
            int right = WIDTH - 1 - layer;
            if (left > right) {
                break;
            }
            
            // top row
            for (int x = left; x <= right; ++x) {
                answer.push_back(matrix[top][x]);
            }
            
            // right column
            for (int y = top + 1; y <= bottom; ++y) {
                answer.push_back(matrix[y][right]);
            }
            
            // bottom row
            if (bottom > top) {
                for (int x = right - 1; x >= left; --x) {
                    answer.push_back(matrix[bottom][x]);
                }
            }
            
            // left column
            if (right > left) {
                for (int y = bottom - 1; y >= top + 1; --y) {
                    answer.push_back(matrix[y][left]);
                }
            }
            
            layer++;
        }
        
        return answer;
    }
};