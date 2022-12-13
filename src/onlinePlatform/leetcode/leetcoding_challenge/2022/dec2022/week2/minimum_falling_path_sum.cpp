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
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // TODO: validate input        
        int WIDTH = matrix[0].size();
        
        if (WIDTH == 1) {
            int answer = 0;
            for (vector<int> row: matrix) {
                answer += row[0];
            }
            return answer;
        }
        
        
        vector<int> dp = vector<int>(WIDTH);
        
        for (vector<int> row: matrix) {
            vector<int> prev = dp;
            dp = vector<int>(WIDTH);
            dp[0] = row[0] + min(prev[0], prev[1]);
            
            for (int x = 1; x <= WIDTH - 2; x++) {
                dp[x] = row[x] + min({prev[x - 1], prev[x], prev[x + 1]});
            }
                
            dp[WIDTH - 1] = row[WIDTH - 1] + min(prev[WIDTH - 2], prev[WIDTH - 1]);
        }
        
        return *min_element(dp.begin(), dp.end());        
    }
};
