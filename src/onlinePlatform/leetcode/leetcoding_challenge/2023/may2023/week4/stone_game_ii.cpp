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

const int MAX_NUM_PILES = 100;
const int UNINITIALIZED = -1;

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        memset(memo, UNINITIALIZED, sizeof memo);
        return getStones(piles, 0, 1, true);
    }
    
private:
    int memo[MAX_NUM_PILES + 1][MAX_NUM_PILES + 1][2];
    
    int getStones(vector<int>& piles, int i, int m, bool isMaximizing) {
        if (i >= piles.size()) {
            return 0;
        }
        
        if (memo[i][m][isMaximizing?0:1] != UNINITIALIZED) {
            return memo[i][m][isMaximizing?0:1];
        }
        
        if (isMaximizing) {
            int currTaking = 0;
            for (int x = 1; (x <= 2 * m) && (i - 1 + x < piles.size()); ++x) {
                currTaking += piles[i - 1 + x];
                memo[i][m][isMaximizing?0:1] = max(
                    memo[i][m][isMaximizing?0:1],
                    currTaking + getStones(piles, i + x, max(m, x), !isMaximizing)
                );
            }
        } else {
            memo[i][m][isMaximizing?0:1] = getStones(piles, i + 1, max(m, 1), !isMaximizing);
            for (int x = 2; (x <= 2 * m) && (i - 1 + x < piles.size()); ++x) {
                memo[i][m][isMaximizing?0:1] = min(
                    memo[i][m][isMaximizing?0:1],
                    getStones(piles, i + x, max(m, x), !isMaximizing)
                );
            }
        }
        
        return memo[i][m][isMaximizing?0:1];
    }
    

};