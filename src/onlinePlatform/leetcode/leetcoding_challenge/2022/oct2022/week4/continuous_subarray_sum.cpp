#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <limits>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <iterator>
#include <sstream>
#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {        
        int MIN_LENGTH_REQUIREMENT = 2;
        
        int fast = 0;
        int slow = 0;
        unordered_set<int> appeared;
        appeared.insert(0);
        
        for (int i = 0; i < nums.size(); i++) {
            fast = (fast + nums[i]) % k;
            
            if (i >= MIN_LENGTH_REQUIREMENT - 1) {                
                if (appeared.count(fast) > 0) {
                    return true;
                }
                slow = (slow + nums[i - (MIN_LENGTH_REQUIREMENT - 1)]) % k;
                appeared.insert(slow);
            }            
        }
        
        return false;
    }
};

class WASolution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {        
        int MIN_LENGTH_REQUIREMENT = 2;
        
        int curr = 0;        
        unordered_set<int> prev;
        
        prev.insert(0);
        for (int i = 0; i < MIN_LENGTH_REQUIREMENT - 1; i++) {
            curr = (curr + nums[i]) % k;
            prev.insert(curr);
        }
        
        
        for (int i = MIN_LENGTH_REQUIREMENT - 1; i < nums.size(); i++) {
            curr = (curr + nums[i]) % k;
            if (prev.count(curr) > 0) {
                return true;
            }
            prev.insert(curr);            
        }
        
        return false;
    }
};

int main() {
    Solution soln;

    vector<int> nums = {1, 0};
    int k = 2;
    cout << soln.checkSubarraySum(nums, k) << endl;
}