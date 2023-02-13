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
    int countOdds(int low, int high) {
        int diff = high - low + 1;
        if (diff % 2 == 0) {
            return diff / 2;
        } else {
            if ((low % 2 != 0) && (high % 2 != 0)) {
                return (diff / 2) + 1;
            } else {
                return diff / 2;
            }
        }
    }
};

int main() {
    Solution soln;

    cout << soln.countOdds(3, 7) << endl;

    return 0;
}