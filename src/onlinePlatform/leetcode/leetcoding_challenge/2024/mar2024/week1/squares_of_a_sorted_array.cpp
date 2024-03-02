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
    vector<int> sortedSquares(vector<int>& nums) {
        int nonNegativeIdx = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= 0) {
                nonNegativeIdx = i;
                break;
            }
        }

        vector<int> answer;

        int negativeIdx = nonNegativeIdx - 1;
        while (negativeIdx >= 0 || nonNegativeIdx < nums.size()) {
            bool moveNonNegative = true;

            if (negativeIdx >= 0 && nonNegativeIdx < nums.size()) {
                if (abs(nums[negativeIdx]) < nums[nonNegativeIdx]) {
                    moveNonNegative = false;
                }
            } else if (negativeIdx >= 0) {
                moveNonNegative = false;
                // } else {
                // negativeIdx >= 0
            }

            if (moveNonNegative) {
                int num = nums[nonNegativeIdx];
                answer.push_back(num * num);

                nonNegativeIdx++;
            } else {
                int num = nums[negativeIdx];
                answer.push_back(num * num);

                negativeIdx--;
            }
        }

        return answer;
    }
};