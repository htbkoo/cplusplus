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
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> counter;
        for (auto num: target) {
            counter[num]++;
        }        
        for (auto num: arr) {
            counter[num]--;
        }
                
        for (auto &[_, count]: counter) {
            if (count > 0) {
                return false;
            }
        }
        return true;
    }
    
};
