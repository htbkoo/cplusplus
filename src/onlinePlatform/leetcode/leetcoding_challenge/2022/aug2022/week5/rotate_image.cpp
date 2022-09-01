#include <algorithm>
#include <vector>
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
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int layer = 0;
        
        while (layer < n - 1 - layer) {
            for (int topX = layer; topX < n - 1 - layer; topX++) {
                int temp = matrix[layer][topX];
                matrix[layer][topX] = matrix[n - 1 - topX][layer];
                matrix[n - 1 - topX][layer] = matrix[n - 1 - layer][n - 1 - topX];
                matrix[n - 1 - layer][n - 1 - topX] = matrix[topX][n - 1 - layer];
                matrix[topX][n - 1 - layer] = temp;
            }            
            layer++;
        }
    }
};

int main() {
    Solution soln;
   
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    soln.rotate(matrix);

    return 0;
}