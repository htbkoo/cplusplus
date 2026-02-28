#include <algorithm>
#include <cmath>
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
    int concatenatedBinary(int n) {
        int MOD = pow(10, 9) + 7;

        long answer = 0;
        for (int x = n; x >= 1; --x) {
            int i = x;
            while (i > 0) {
                // answer = (answer * 2 + i % 2) % MOD;
                answer = (answer * 2l + static_cast<long>(i) % 2l);
                i /= 2;
            }
        }

        return answer;
    }
};

int main() {
    Solution soln;
    cout << soln.concatenatedBinary(12) << endl;
    return 0;
}