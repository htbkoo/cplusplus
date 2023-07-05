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
    int longestSubarray(vector<int>& nums) {
        if (nums.size() == 0) {
            // TODO: confirm this
            return 0;
        }
        
        vector<int> leftToRight(nums.size(), 0);
        vector<int> rightToLeft(nums.size(), 0);
        
        for (int i = 1; i < nums.size(); ++i) {
            leftToRight[i] = leftToRight[i - 1] + 1;
            if (nums[i - 1] != 1) {
                leftToRight[i] = 0;
            }
        }

        for (int i = nums.size() - 2; i >= 0; --i) {
            rightToLeft[i] = rightToLeft[i + 1] + 1;
            if (nums[i + 1] != 1) {
                rightToLeft[i] = 0;
            }
        }
        
        int answer = leftToRight[0] + rightToLeft[0];
        for (int i = 1; i < nums.size(); ++i) {
            answer = max(answer, leftToRight[i] + rightToLeft[i]);
        }
        
        return answer;
    }
};

class WASolution {
public:
    int longestSubarray(vector<int>& nums) {
        if (nums.size() == 0) {
            // TODO: confirm this
            return 0;
        }
        
        vector<int> leftToRight(nums.size(), 0);
        vector<int> rightToLeft(nums.size(), 0);
        
        int currCount = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] == 1) {
                currCount++;
            }
            leftToRight[i] = currCount;
        }
            
        currCount = 0;
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i + 1] == 1) {
                currCount++;
            }
            rightToLeft[i] = currCount;
        }
        
        int answer = leftToRight[0] + rightToLeft[0];
        for (int i = 1; i < nums.size(); ++i) {
            answer = max(answer, leftToRight[i] + rightToLeft[i]);
        }
        
        return answer;
    }
};

int main() {
    Solution soln;
    vector<int> nums{0,1,1,1,0,1,1,0,1};
    cout << soln.longestSubarray(nums) << endl;

    return 0;
}