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
    int rob(vector<int>& nums) {
        int rob = 0;
        int noRob = 0;
        
        for (int val: nums) {
            int tempRob = rob;
            int tempNoRob = noRob;
            
            rob = max(tempRob, tempNoRob + val);
            noRob = max(tempNoRob, tempRob);
        }
        
        return max(rob, noRob);
    }
};

class WASolution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        } else if (nums.size() == 1) {
            return max(nums[0], 0);
        }
        
        int first = max(nums[0], 0);
        int second = max(nums[1], 0);
        
        for (int i = 2; i < nums.size(); i++) {
            int val = max(nums[i], 0);
            
            int temp = second;
            second = max(second, first + val);
            first = max(temp, first);
        }
        
        return max(first, second);
    }
};