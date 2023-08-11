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
    int change(int amount, vector<int>& coins) {
        vector<int> numWays(amount + 1, 0);
        numWays[0] = 1;
        
        for (auto coin: coins) {
            for (int c = coin; c <= amount; ++c) {
                numWays[c] += numWays[c - coin];
            }
        }
        
        return numWays[amount];
    }
};