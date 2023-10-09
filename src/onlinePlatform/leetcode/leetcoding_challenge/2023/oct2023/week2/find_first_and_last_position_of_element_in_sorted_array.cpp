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
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return {-1, -1};
        } 
        
        auto lo = lower_bound(begin(nums), end(nums), target);
        auto hi = upper_bound(begin(nums), end(nums), target);
        
        int idxLo = distance(begin(nums), lo);
        int idxHi = distance(begin(nums), hi);
        
        if (idxLo == idxHi) {
            return {-1, -1};
        } else {
            return {idxLo, idxHi - 1};
        }
    }
};