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
#include <cstring> // for memset
using namespace std; // since cin and cout are both in namespace std, this saves some text

const int MAX_S_SIZE = 500;
const int UNINITIALIZED = -1;

class Solution {
public:
    int minInsertions(string s) {
        memset(memo, UNINITIALIZED, sizeof(memo));
        return findMin(s, 0, s.size() - 1);
    }
    
private:
    int memo[MAX_S_SIZE + 1][MAX_S_SIZE + 1];
    
    int findMin(string& s, int lo, int hi) {
        if (memo[lo][hi] != UNINITIALIZED) {
            return memo[lo][hi];
        }
        if (lo >= hi) {
            return 0;
        }
        if (s[lo] == s[hi]) {
            memo[lo][hi] = findMin(s, lo + 1, hi - 1);
        } else {
            memo[lo][hi] = 1 + min(
                findMin(s, lo + 1, hi),
                findMin(s, lo, hi - 1)
            );        
        }
        
        return memo[lo][hi];
    }
};