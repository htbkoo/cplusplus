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
    bool validPartition(vector<int>& nums) {
        bool prevprev = false, prev = false, curr = true;
        
        for (int i = 0; i < nums.size(); ++i) {
            bool tempprevprev = prevprev, tempprev = prev, tempcurr = curr;
            
            bool canPartitionWithTwoElements = tempprev && i > 0 && nums[i] == nums[i - 1];
            bool canPartitionWithThreeElements = tempprevprev && i > 1 && ( (nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2]) || (nums[i] == nums[i - 1] + 1 && nums[i - 1] == nums[i - 2] + 1) );
            curr = canPartitionWithTwoElements || canPartitionWithThreeElements;
            prev = tempcurr;
            prevprev = tempprev;
        }
        
        return curr;
    }
};