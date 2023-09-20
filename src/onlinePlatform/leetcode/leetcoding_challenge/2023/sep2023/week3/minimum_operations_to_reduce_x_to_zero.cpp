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
    int minOperations(vector<int>& nums, int x) {
        // vector<int> prefixSums{0};
        
        int prev = 0;
        
        unordered_map<int, int> positions;        
        positions[prev] = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            // int prev = prefixSums.back();
            
            // TODO: verify no overflow, otherwise use long
            prev += num;
            if (positions.count(prev) == 0) {
                positions[prev] = i + 1;
            }
        }
        
        int answer = numeric_limits<int>::max();
        if (positions.count(x) > 0) {
            answer = positions[x];
        }
        
        int curr = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            int num = nums[i];
            curr += num;
            
            int remain = x - curr;
            
            if (positions.count(remain) > 0) {
                answer = min(answer, positions[remain] + (int) nums.size() - i);
            }
        }
        
        if (answer > nums.size()) {
            return -1;
        } else {
            return answer;
        }
    }
};