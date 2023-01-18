#include <algorithm>
#include <vector>
#include <set>
#include <limits>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <sstream>
#include <queue>
#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long answer = numeric_limits<long>::min();
        long currSum = 0;
        
        for (int num: nums) {
            if (currSum < 0) {
                currSum = num;
            } else {
                currSum += num;
            }
            answer = max(answer, currSum);
        }
        
        return answer;
    }
};
