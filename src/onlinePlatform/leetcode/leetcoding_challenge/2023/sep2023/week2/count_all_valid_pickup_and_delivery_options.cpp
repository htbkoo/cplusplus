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

const int UNINITIALIZED = -1;
const int MOD = 1e9 + 7;

class Solution {
public:
    int countOrders(int n) {
        memo = vector<vector<int>>();
        for (int i = 0; i <= n; ++i) {
            memo.push_back(vector<int>(n + 1, UNINITIALIZED));
        }
        
        return count(n, 0);
    }

private:
    vector<vector<int>> memo;
    long count(int p, int d) {
        if (memo[p][d] == UNINITIALIZED) {                    
            if (p == 0 && d == 0) {
                memo[p][d] = 1;
            }
            else if (p == 0) {
                memo[p][d] = (d * count(p, d - 1)) % MOD;
            }
            else if (d == 0) {
                memo[p][d] = (p * count(p - 1, d + 1)) % MOD;
            } else {
                memo[p][d] = (p * count(p - 1, d + 1) + d * count(p, d - 1)) % MOD;
            }
        }
        return memo[p][d];
    }
};
