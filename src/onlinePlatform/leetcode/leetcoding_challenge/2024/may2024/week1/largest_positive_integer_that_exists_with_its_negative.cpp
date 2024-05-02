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
    int findMaxK(vector<int>& nums) {
        unordered_set<int> numsSet(begin(nums), end(nums));
        
        int answer = -1;
        
        for (auto num: nums) {
            if (num > 0 && numsSet.count(-num) > 0) {
                answer = max(answer, num);
            }
        }
        
        return answer;
    }
};