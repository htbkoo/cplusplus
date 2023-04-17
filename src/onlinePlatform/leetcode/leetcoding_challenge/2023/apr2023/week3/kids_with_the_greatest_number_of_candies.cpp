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
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        long maxCandies = (long) *max_element(candies.begin(), candies.end());
        
        vector<bool> result;
        for (auto candy: candies) {
            bool isGreater = (long) candy + (long) extraCandies >= maxCandies;
            result.push_back(isGreater);
        }
        
        return result;
    }
};