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
    int countVowelPermutation(int n) {
        // vector<char> VOWELS = {'a', 'e', 'i', 'o', 'u'};
        
        if (n == 0) {
            return 0;
        }
        
        int MOD = 1e9 + 7;
        
        long a = 1, e = 1, i = 1, o = 1, u = 1;
        
        for (int x = 2; x <= n; ++x) {
            long prev_a = a, prev_e = e, prev_i = i, prev_o = o, prev_u = u;
            
            a = ((prev_e + prev_u) % MOD + prev_i) % MOD;
            e = (prev_a + prev_i) % MOD;
            i = (prev_e + prev_o) % MOD;
            o = prev_i;
            u = (prev_i + prev_o) % MOD;
        }
            
        return (a + e + i + o + u) % MOD;
    }
};