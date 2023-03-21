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
    long long zeroFilledSubarray(vector<int>& nums) {
        long long answer = 0;
        long long currLen = 0;
        
        for (auto num: nums) {
            if (num == 0) {
                currLen++;
                answer += currLen;
            } else {
                currLen = 0;
            }
        }
        
        return answer;
    }
};
