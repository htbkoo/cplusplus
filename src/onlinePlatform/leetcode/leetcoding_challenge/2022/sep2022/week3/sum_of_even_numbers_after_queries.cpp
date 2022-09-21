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
#include <string>
#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> answer;
        
        long currEvenSum = 0;
        for (int num: nums) {
            if (num % 2 == 0) {
                currEvenSum += num;
            }
        }
        
        for (auto query: queries) {
            int val = query[0], idx = query[1];
            
            if (nums[idx] % 2 == 0) {
                currEvenSum -= nums[idx];
            }
            
            nums[idx] += val;
            
            if (nums[idx] % 2 == 0) {
                currEvenSum += nums[idx];
            }
            
            answer.push_back(currEvenSum);
        }
        
        return answer;
    }
};