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
    int maxProductDifference(vector<int>& nums) {
        sort(begin(nums), end(nums));

        // TODO: what if nums.size() < 4

        return nums[nums.size() - 1] * nums[nums.size() - 2] - nums[0] * nums[1];
    }
};