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
    int numDecodings(string s) {
        memo = unordered_map<int, int>();
        
        return count(s, 0);
    }

    int count(string s, int i) {
        if (i >= s.size()) {
            return 1;
        }
        if (memo.count(i) > 0) {
            return memo[i];
        }
        if (s[i] == '0') {
            // no ways if starting with '0'
            memo[i] = 0;
        } else {
            memo[i] = count(s, i + 1);
            
            if (i <= s.size() - 2) {
                string twoDigitsAtI = s.substr(i, 2);
                int value = stoi(twoDigitsAtI);
                if (value >= 10 && value <= 26) {
                    memo[i] += count(s, i + 2);
                }
            }
        }

        return memo[i];
    }


private:
    unordered_map<int, int> memo;
};