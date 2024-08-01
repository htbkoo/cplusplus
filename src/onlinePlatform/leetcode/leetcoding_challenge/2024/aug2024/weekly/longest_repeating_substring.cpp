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
    int longestRepeatingSubstring(string s) {
        int lo = 0;
        int hi = s.size();
        
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            
            if (hasRepeating(s, mid)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        
        return lo;
    }
    
private:
    bool hasRepeating(string &s, int mid) {
        for (int i = 0; i + mid <= s.size(); ++i) {
            if (s.npos != s.find(s.substr(i, mid), i + 1)) {
                return true;
            }               
        }
            
        return false;
    }
};
