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
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int flipCounts = 0;
        int minDiff = numeric_limits<int>::max();
        long long best = 0;
        for (auto num: nums) {
            int flip = num ^ k;
            if (flip > num) {
                flipCounts++;
            }
            best += max(flip, num);
            minDiff = min(minDiff, abs(flip - num));
        }

        if (flipCounts % 2 == 0) {
            return best;
        } else {
            return best - minDiff;
        }
    }
};
