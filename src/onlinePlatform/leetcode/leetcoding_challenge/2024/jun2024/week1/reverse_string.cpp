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
    void reverseString(vector<char>& s) {
        int lo = 0;
        int hi = s.size() - 1;

        while (lo < hi) {
            auto temp = s[lo];
            s[lo] = s[hi];
            s[hi] = temp;

            lo++;
            hi--;
        }
    }
};
