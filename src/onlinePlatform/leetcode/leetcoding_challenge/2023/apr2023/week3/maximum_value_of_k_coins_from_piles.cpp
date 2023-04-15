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
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memo = unordered_map<int, unordered_map<int, long>>();
        return findMax(piles, k, 0);
    }
    
private:
    unordered_map<int, unordered_map<int, long>> memo;
    
    long findMax(vector<vector<int>>& piles, int k, int i) {
        if (memo.count(k) > 0 && memo[k].count(i) > 0) {
            return memo[k][i];
        }
        
        if (k == 0) {
            return 0;
        }
        if (i >= piles.size()) {
            return numeric_limits<int>::min();
        }
        
        int currCoins = 0;
        
        memo[k][i] = findMax(piles, k, i + 1);
        
        int maxCount = min(k + 1, (int) piles[i].size());        
        for (int j = 0; j < maxCount; j++) {
            currCoins += piles[i][j];
            memo[k][i] = max(
                memo[k][i],
                currCoins + findMax(piles, k - j - 1, i + 1)
            );
        }
        
        return memo[k][i];
    }   
};