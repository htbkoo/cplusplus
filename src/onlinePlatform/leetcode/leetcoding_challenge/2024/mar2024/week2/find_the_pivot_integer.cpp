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
    int pivotInteger(int n) {
        // TODO: handle overflow
        long right = (1 + n) * n / 2;
        long left = 0;

        for (int i = 1; i <= n; i++) {
            left += i;
            if (left == right) {
                return i;
            }
            right -= i;
        }

        return -1;
    }
};