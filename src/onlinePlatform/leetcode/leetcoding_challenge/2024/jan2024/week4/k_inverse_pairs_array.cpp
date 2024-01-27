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
    int kInversePairs(int n, int k) {
        int MOD = pow(10, 9) + 7;

        vector<long> counts{1};

        for (int i = 1; i < n; i++) {
            int size = min((i * (i + 1)) / 2, k) + 1;
            vector<long> prev = counts;
            counts = vector<long>(size, 0);

            int left = 0;
            long curr = 0;
            for (int right = 0; right < size; right++) {
                if (right < prev.size()) {
                    curr = curr + prev[right];
                }
                counts[right] = curr % MOD;
                if (right >= i) {
                    curr = curr - prev[left];
                    left++;
                }
            }
        }

        if (k >= counts.size()) {
            return 0;
        }

        return counts[k];
    }
};

int main() {
    Solution soln;

    cout << soln.kInversePairs(1, 1) << endl;

    return 0;
}