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
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;

        for (auto num: nums) {
            // int idx = distance(begin(lis), upper_bound(begin(lis), end(lis), num));
            int idx = distance(begin(lis), lower_bound(begin(lis), end(lis), num));

            if (idx < lis.size()) {
                lis[idx] = num;
            } else {
                lis.push_back(num);
            }
        }

        return lis.size();
    }
};
