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
    int search(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        if (it != nums.end() && *it == target) {
            return distance(nums.begin(), it);
        } else {
            return -1;
        }
    }
};


class FirstSolution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int val = nums[mid];
            if (target > val) {
                lo = mid + 1;
            } else if (target < val) {
                hi = mid - 1;
            } else {
                return mid;
            }
        }
        
        return -1;
    }
};