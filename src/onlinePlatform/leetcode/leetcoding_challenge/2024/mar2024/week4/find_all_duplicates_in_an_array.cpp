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
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> answer;
        for (auto num: nums) {
            int idx = abs(num) - 1;
            if (nums[idx] < 0) {
                answer.push_back(abs(num));
            }
            nums[idx] = -nums[idx];
        }

        return answer;
    }
};
