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

const int MOD = 1e9 + 7;
const vector<vector<int>> NEXT_KEYS = {
    {4, 6},
    {6, 8},
    {7, 9},
    {4, 8},
    {3, 9, 0},
    {},
    {1, 7, 0},
    {2, 6},
    {1, 3},
    {2, 4},
};

class Solution {
public:
    int knightDialer(int n) {
        vector<int> counts(10, 1);

        for (int j = 2; j <= n; ++j) {
            vector<int> prev = counts;
            counts = vector<int>(10, 0);

            for (int i = 0; i < 10; ++i) {
                for (int n: NEXT_KEYS[i]) {
                    counts[n] = (counts[n] + prev[i]) % MOD;
                }
            }
        }


        int answer = 0;
        for (int i = 0; i < 10; ++i) {
            answer = (answer + counts[i]) % MOD;
        }
        return answer;
    }
};

int main() {
    Solution soln;

    cout << soln.knightDialer(5) << endl;

    return 0;
}
