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
    int minSubArrayLen(int target, vector<int>& nums) {
        int answer = numeric_limits<int>::max();
        
        long long currSum = 0;
        int left = 0;
        int right = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            currSum += nums[right];
            while (currSum >= target && left <= right) {
                int length = right - left + 1;
                answer = min(answer, length);
                currSum -= nums[left];
                left++;
            }
        }
        
        if (answer < numeric_limits<int>::max()) {
            return answer;
        } else {
            return 0;
        }
    }
};