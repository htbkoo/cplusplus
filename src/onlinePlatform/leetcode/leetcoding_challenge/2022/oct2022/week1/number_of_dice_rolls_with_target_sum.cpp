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
    int numRollsToTarget(int n, int k, int target) {
        int MOD = 1000000007;

        vector<long> dp = vector<long>(target + 1);
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = target; j >= 0; j--) {
                dp[j] = 0;
                for (int m = j - 1; m >= max(0, j - k); m--) {
                    dp[j] = (dp[j] + dp[m]) % MOD;
                }
            }
        }

        return dp[target] % MOD;
    }
};

int main() {
    Solution soln;

    soln.numRollsToTarget(1, 6, 3);

    return 0;
}