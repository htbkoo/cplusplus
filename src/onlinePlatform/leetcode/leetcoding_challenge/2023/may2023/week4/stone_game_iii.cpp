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

const int MAX_NUM_STONES = 5e4;
const int NUM_PLAYERS = 2;
const int UNINITIALIZED = -1;

const int MIN_TAKE = 1;
const int MAX_TAKE = 3;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        memset(memo, UNINITIALIZED, sizeof(memo));
        
        long result = findResult(stoneValue, 0, 1);
        
        if (result > 0) {
            return "Alice";
        } else if (result < 0) {
            return "Bob";
        } else {
            return "Tie";
        }
    }
    
private:
    long memo[MAX_NUM_STONES + 1][NUM_PLAYERS];

    long findResult(vector<int>& stoneValue, int i, int sign) {
        if (i >= stoneValue.size()) {
            return 0;
        }
        
        int playerId = (sign == 1) ? 0 : 1;
        if (memo[i][playerId] == UNINITIALIZED) {
            if (sign > 0) {
                // to maximize the result
                long curr = stoneValue[i];
                memo[i][playerId] = curr + findResult(stoneValue, i + 1, -sign);

                for (int x = MIN_TAKE + 1; x <= MAX_TAKE && (i - 1 + x) < stoneValue.size(); ++x) {
                    curr += stoneValue[i - 1 + x];
                    memo[i][playerId] = max(
                        memo[i][playerId],
                        curr + findResult(stoneValue, i + x, -sign)
                    );
                }
            } else {            
                // to minimize the result
                long curr = stoneValue[i];
                memo[i][playerId] = -curr + findResult(stoneValue, i + 1, -sign);

                for (int x = MIN_TAKE + 1; x <= MAX_TAKE && (i - 1 + x) < stoneValue.size(); ++x) {
                    curr += stoneValue[i - 1 + x];
                    memo[i][playerId] = min(
                        memo[i][playerId],
                        -curr + findResult(stoneValue, i + x, -sign)
                    );
                }
            }
        }
        
        return memo[i][playerId];
    }
};

int main() {
    Solution soln;

    vector<int> values = {1,2,3,7};
    // vector<int> values = {1,2,3,-9};
    // vector<int> values = {1,2,3,6};

    cout << soln.stoneGameIII(values) << endl;

    return 0;
}