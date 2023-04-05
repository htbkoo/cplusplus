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
    int minimizeArrayValue(vector<int>& nums) {
        long long answer = 0;
        long long cumulative = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            cumulative += num;
            int count = i + 1;
            long long avg = (cumulative + count - 1) / count;
            answer = max(answer, avg);
        }
        
        return answer;
    }
};
