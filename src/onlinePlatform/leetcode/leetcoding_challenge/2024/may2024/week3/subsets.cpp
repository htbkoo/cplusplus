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
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;

        for (int i = 0; i < (int) pow(2, nums.size()); ++i) {
            answer.push_back(build(nums, i));
        }

        return answer;
    }

private:
    vector<int> build(vector<int>& nums, int bitmask) {
        vector<int> v;

        for (auto num: nums) {
            if (bitmask % 2 == 1) {
                v.push_back(num);
            }
            bitmask /= 2;
        }

        return v;
    }
};
