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
    map<int, map<int, int>> memo;
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size();
        vector<long> dp;
        for (int i = 0; i < m; i++) {
            dp.push_back(numeric_limits<long>::min());
        }

        for (int lo = m - 1; lo >= 0; lo--) {
            long prev = dp[dp.size() - 1];
            dp[dp.size() - 1] = max(
                multipliers[multipliers.size() - 1] * nums[lo],
                multipliers[multipliers.size() - 1] * nums[nums.size() - 1 - (m - 1 - lo)]
            );

            for (int i = m - 1; i >= lo + 1; i--) {
                int j = m - i;
                
                long temp = dp[i - 1];
                dp[i - 1] = max(
                    multipliers[multipliers.size() - 1 - j] * nums[lo] + prev,
                    multipliers[multipliers.size() - 1 - j] * nums[nums.size() - 1 - (m - 1 - (lo + j))] + dp[i]
                );
                prev = temp;
            }
        }

        return dp[0];
    }
};

class TLESolution {
public:
    map<int, map<int, int>> memo;
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        return findMaxScore(nums, multipliers, 0, nums.size() - 1);
    }
    
    int findMaxScore(vector<int>& nums, vector<int>& multipliers, int lo, int hi) {
        int leftCount = lo;
        int rightCount = nums.size() - hi - 1;
        int i = leftCount + rightCount;
        
        if (i >= multipliers.size()) {
            return 0;
        }
        
        if (memo.count(lo) > 0 && memo[lo].count(hi) > 0) {
            return memo[lo][hi];
        }
        
        if (memo.count(lo) == 0) {
            memo[lo] = map<int, int>();
        }
        
        int startValue = multipliers[i] * nums[lo] + findMaxScore(nums, multipliers, lo + 1, hi);
        int endValue = multipliers[i] * nums[hi] + findMaxScore(nums, multipliers, lo, hi - 1);
        
        memo[lo][hi] = max(startValue, endValue);
        return memo[lo][hi];
    }
};