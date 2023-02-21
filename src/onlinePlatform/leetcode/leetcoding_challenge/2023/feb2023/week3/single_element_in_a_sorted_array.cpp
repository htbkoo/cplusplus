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
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            bool isLeftFulfill = mid == 0 || nums[mid] != nums[mid - 1];
            bool isRightFulfill = mid == nums.size() - 1 || nums[mid] != nums[mid + 1];
            
            if (isLeftFulfill && isRightFulfill) {
                return nums[mid];
            } else if (!isLeftFulfill && !isRightFulfill) {
                throw invalid_argument("there are no matches, final posisition: " + to_string(mid));
            } else {
                bool shouldRightEqual = mid % 2 == 0;                
                if (shouldRightEqual == isLeftFulfill) {
                    lo = mid + 1;                    
                } else {
                    hi = mid - 1;
                } 
            } 
        }
        
        throw invalid_argument("there are no matches, final posisition: " + to_string(lo));
    }
};

class FirstSolution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int answer = 0;
        for (int num: nums) {
            answer ^= num;
        }
        return answer;
    }
};
