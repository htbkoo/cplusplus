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
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));

        int answer = -1;

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int s = nums[left] + nums[right];
            if (s < k) {
                answer = max(answer, s);
                left += 1;
            } else {
                right -= 1;
            }
        }

        return answer;
    }
};