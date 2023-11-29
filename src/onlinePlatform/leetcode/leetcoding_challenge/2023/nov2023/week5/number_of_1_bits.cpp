#include <algorithm>
#include <cstdint>
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
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n != 0) {
            if (n % 2 != 0) {
                count += 1;
            }
            n >>= 1;
        }
        return count;
    }
};

int main() {
    Solution soln;

    cout << soln.hammingWeight(00000000000000000000000000001011) << endl;

    return 0;
}