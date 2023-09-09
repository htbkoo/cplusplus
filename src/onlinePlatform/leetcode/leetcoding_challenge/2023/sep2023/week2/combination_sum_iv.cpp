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
    int combinationSum4(vector<int>& nums, int target) {
        long MOD = 2147483647;
        
        vector<long> numWays(target + 1, 0);
        numWays[0] = 1;
        
        for (int i = 1; i <= target; ++i) {
            for (int num: nums) {
                if (i < num) {
                    continue;
                }
                numWays[i] = (numWays[i] + numWays[i - num]) % MOD;
            }
        }
        
        return numWays[target];
    }
};
