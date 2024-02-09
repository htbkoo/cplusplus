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

const int UNINITIALIZED = -1;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        memo = vector<vector<pair<int, bool>>>();
        for (int i = 0; i <= nums.size(); ++i) {
            memo.push_back(vector<pair<int, bool>>(nums.size() + 1, pair{UNINITIALIZED, false}));
        }

        sort(begin(nums), end(nums));

        findLargestSize(nums, 0, nums.size());

        vector<int> answer;
        int j = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            if (memo[i][j].second) {
                answer.push_back(nums[i]);
                j = i;
            }
        }

        return answer;
    }

private:
    vector<vector<pair<int, bool>>> memo;

    int findLargestSize(vector<int>& nums, int i, int j) {
        if (i >= nums.size()) {
            return 0;
        }

        if (memo[i][j].first == UNINITIALIZED) {
            memo[i][j] = pair{findLargestSize(nums, i + 1, j), false}; // skip this num

            if (j == nums.size() || nums[i] % nums[j] == 0) {
                int sizeWithNum = 1 + findLargestSize(nums, i + 1, i);
                if (sizeWithNum > memo[i][j].first) {
                    memo[i][j] = pair{sizeWithNum, true}; // take this num
                }
            }
        }

        return memo[i][j].first;
    }
};

class WASolution2 {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        memo = vector<vector<int>>();
        for (int i = 0; i <= nums.size(); ++i) {
            memo.push_back(vector<int>(nums.size() + 1, UNINITIALIZED));
        }

        sort(begin(nums), end(nums));
        return {};
        // return findLargestSize(nums, 0, nums.size());
    }

private:
    vector<vector<int>> memo;

    int findLargestSize(vector<int>& nums, int i, int j) {
        if (i >= nums.size()) {
            return 0;
        }

        if (memo[i][j] == UNINITIALIZED) {
            memo[i][j] = findLargestSize(nums, i + 1, j); // skip this num

            if (j == nums.size() || nums[i] % nums[j] == 0) {
                memo[i][j] = max(memo[i][j], findLargestSize(nums, i + 1, i)); // take this num
            }
        }

        return memo[i][j];
    }
};

class WASolution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        return {};
        unordered_set<int> numsSet(begin(nums), end(nums));

        for (auto base: numsSet) {

        }

    }
};

int main() {
    Solution soln;

    // vector<int> nums{1,2,3};
    vector<int> nums{1,2,4,8};

    auto answer = soln.largestDivisibleSubset(nums);
    // cout <<  << endl;

    return 0;
}