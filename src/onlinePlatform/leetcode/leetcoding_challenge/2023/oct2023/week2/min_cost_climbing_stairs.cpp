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
    int minCostClimbingStairs(vector<int>& cost) {
        int pp = cost[0], p = cost[1];
        
        for (int i = 2; i < cost.size(); ++i) {
            int better = min(pp, p);
            pp = p;
            p = better + cost[i];
        }
        
        return min(pp, p);
    }
};