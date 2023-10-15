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
    int numWays(int steps, int arrLen) {
        int MOD = 1e9 + 7;
        int START = 0;
        vector<int> count(min(steps + 1, arrLen), 0);
        count[START] = 1;
        
        for (int s = 1; s <= steps; ++s) {
            vector<int> prev = count;
            count = vector<int>(begin(prev), end(prev));
            
            for (int c = 0; c < count.size(); ++c) {
                if (c > 0) {
                    count[c] = (count[c] + prev[c - 1]) % MOD;
                }
                if (c < count.size() - 1) {
                    count[c] = (count[c] + prev[c + 1]) % MOD;
                }
            }
        }
        
        return count[0];
    }
};