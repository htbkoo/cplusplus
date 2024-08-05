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
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> counter;
        for (auto &s: arr) {
            counter[s]++;
        }
        
        for (auto &s: arr) {
            if (counter[s] == 1) {
                k--;
                if (k == 0) {
                    return s;
                }
            }
        }
        
        return "";
    }
};
