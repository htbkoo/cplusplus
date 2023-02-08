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
    int jump(vector<int>& nums) {
        int numJumps = 0;
        int maxReach = 0;
        int nextReach = 0;
        
        for (int i = 0; i < nums.size() - 1; i++) {            
            nextReach = max(nextReach, i + nums[i]);
            if (nextReach >= nums.size() - 1) {
                return numJumps + 1;
            }
            
            if (i + 1 > maxReach) {             
                numJumps++;
                maxReach = nextReach;
            }
        }
        
        return numJumps;
    }
};
