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
    bool isPowerOfFour(int n) {
        if (n <= 0) {
            return false;
        }
        
        long base = 1;
        while (base <= n) {
            if (base == n) {
                return true;
            }
            base *= 4;
        }
        
        return false;
    }
};