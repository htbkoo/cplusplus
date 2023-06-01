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

const int MAX_NUM_CUTS = 100;
const int UNINITIALIZED = -1;

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        if (cuts.size() == 0) {
            return 0;
        }
        
        sort(cuts.begin(), cuts.end());
        
        memset(memo, UNINITIALIZED, sizeof(memo));
        
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        
        return findMin(cuts, 0, cuts.size() - 1);
    }
    
private:
    int memo[MAX_NUM_CUTS + 10][MAX_NUM_CUTS + 10];

    int findMin(vector<int>& cuts, int lo, int hi) {
        if (hi - lo <= 1) {
            return 0;
        }
        
        if (memo[lo][hi] == UNINITIALIZED) {
            int cutCost = cuts[hi] - cuts[lo];
            memo[lo][hi] = cutCost + findMin(cuts, lo, lo + 1) + findMin(cuts, lo + 1, hi);
            for (int idx = lo + 2; idx < hi; ++idx) {
                memo[lo][hi] = min(
                    memo[lo][hi],
                    cutCost + findMin(cuts, lo, idx) + findMin(cuts, idx, hi)
                );
            }
            
        }
        
        return memo[lo][hi];
    }
};