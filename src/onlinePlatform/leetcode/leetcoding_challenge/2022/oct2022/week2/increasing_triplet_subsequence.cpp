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
    bool increasingTriplet(vector<int>& nums) {
        int first = numeric_limits<int>::max();        
        int second = numeric_limits<int>::max();        
        for (int num: nums) {
            if (num > second) {
                return true;
            } else if (num < first) {
                first = num;
            } else if (num < second && num > first) {
                second = num;
            }
        }
        
        return false;
    }
};

class FirstSolution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<bool> hasSmallerLeft = vector<bool>(nums.size());
        
        int currMin = numeric_limits<int>::max();        
        for (int i = 0; i < nums.size(); i++) {
            if (currMin < nums[i]) {
                hasSmallerLeft[i] = true;
            }
            currMin = min(currMin, nums[i]);
        }
        
        int currMax = numeric_limits<int>::min();                
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (currMax > nums[i] && hasSmallerLeft[i]) {
                return true;
            }
            currMax = max(currMax, nums[i]);
        }
        
        return false;
    }
};