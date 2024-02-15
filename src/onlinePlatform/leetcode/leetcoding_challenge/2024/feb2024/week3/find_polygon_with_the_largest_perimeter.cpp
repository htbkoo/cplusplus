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

#include <algorithm>

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        if (nums.size() < 3) {
            return -1;
        }

        sort(begin(nums), end(nums));

        long answer = -1;
        long remain = nums[0] + nums[1];

        for (int i = 2; i < nums.size(); ++i) {
            if (remain > nums[i]) {
                answer = remain + nums[i];
            }
            remain += nums[i];
        }

        return answer;
    }

private:
    int sum(vector<int>& nums) {
        int total = 0;
        for (auto num: nums) {
            total += num;
        }
        return total;
    }
};

class WASolution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int largest = *max_element(begin(nums), end(nums));

        int total = sum(nums);

        int remain = total - largest;

        if (remain > largest) {
            return total;
        } else {
            return -1;
        }

    }

private:
    int sum(vector<int>& nums) {
        int total = 0;
        for (auto num: nums) {
            total += num;
        }
        return total;
    }
};