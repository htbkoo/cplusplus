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
    int removeDuplicates(vector<int>& nums) {        
        if (nums.size() <= 1) {
            return nums.size();
        }
        
        int left = 0;
        int right = 0;
        
        while (right < nums.size() && left < nums.size() - 1) {
            if (nums[left] == nums[right]) {
                right++;
            } else {
                nums[left + 1] = nums[right];
                left++;
                right++;
            }
        } 
        
        return left + 1;
    }
};