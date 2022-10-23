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
    vector<int> findErrorNums(vector<int>& nums) {
        int dup = -1;
        int missing = -1;
        
        unordered_set<int> appeared;        
        for (int num: nums) {
            if (appeared.count(num) > 0) {
                dup = num;
            }
            appeared.insert(num);
        }
        
        for (int i = 1; i <= nums.size(); i++) {
            if (appeared.count(i) == 0) {
                missing = i;
                break;
            }
        }
        
        return vector<int>{dup, missing};
    }
};