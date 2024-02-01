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
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        if (nums.size() == 0) {
            return {};
        }

        sort(begin(nums), end(nums));

        int ARRAY_SIZE = 3;
        vector<vector<int>> answer{{}};

        for (auto num: nums) {
            if (answer.back().size() >= ARRAY_SIZE) {
                answer.push_back({});
            }
            answer.back().push_back(num);
            if (answer.back().back() - answer.back().front() > k) {
                return {};
            }
        }

        return answer;
    }
};

int main() {
    vector<int> nums{1,3,4,8,7,9,3,5,1};
    Solution soln;

    auto answer = soln.divideArray(nums, 2);

    return 0;
}