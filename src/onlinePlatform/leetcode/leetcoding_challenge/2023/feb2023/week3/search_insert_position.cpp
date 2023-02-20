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
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (target < nums[mid]) {
                hi = mid;
            } else if (target > nums[mid]) {
                lo = mid + 1;
            } else {
                return mid;
            }
            
        }
        
        if (target > nums[lo]) {
            return lo + 1;
        } else {
            return lo;
        }
    }
};

class FirstSolution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        
        return distance(nums.begin(), it);
    }
};

int main() {
    Solution soln;

    vector<int> nums = {1,3,5,6};
    int target = 5;

    cout << soln.searchInsert(nums, target) << endl;

    return 0;
}