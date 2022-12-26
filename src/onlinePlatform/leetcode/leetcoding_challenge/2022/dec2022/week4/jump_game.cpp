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
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int curr = 0;
        while (curr <= maxReach && maxReach < nums.size() - 1) {
            maxReach = max(maxReach, curr + nums[curr]);
            curr++;
        }
        
        return maxReach >= nums.size() - 1;
    }
};