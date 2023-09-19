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
    int findDuplicate(vector<int>& nums) {
        int answer = -1;
        for (int i = 0; i < nums.size(); ++i) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0) {
                answer = abs(nums[i]);
                break;
            } else {                
                nums[idx] = -nums[idx];
            }
        }
        
        // restoring nums
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = abs(nums[i]);
        }
        
        return answer;
    }
};
