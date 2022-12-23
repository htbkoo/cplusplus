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
    int maxProfit(vector<int>& prices) {
        int have = numeric_limits<int>::min(), no = 0, cd = numeric_limits<int>::min();
        
        for (int price: prices) {
            int th = have, tn = no, tc = cd;
            
            have = max(have, tn - price);
            no = max(no, tc);
            cd = max(cd, th + price);
        }
        
        return max({have, no, cd});
    }
};