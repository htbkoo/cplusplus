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
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size(), 1);
        vector<int> right(nums.size(), 1);

        for (int i = 1; i < nums.size(); ++i) {
            // TODO: handle overflow
            left[i] = left[i - 1] * nums[i - 1];
        }

        for (int i = nums.size() - 2; i >= 0; --i) {
            // TODO: handle overflow
            right[i] = right[i + 1] * nums[i + 1];

        }

        vector<int> answer(nums.size(), 1);
        for (int i = 0; i < nums.size(); ++i) {
            // TODO: handle overflow
            answer[i] = left[i] * right[i];
        }

        return answer;
    }
};
