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
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> isPossible(s.size(), false);
        isPossible[0] = true;
        
        for (int i = 1; i <= s.size(); ++i) {
            for (auto word: wordDict) {
                if (i >= word.size() && s.substr(i - word.size(), word.size()) == word) {
                    isPossible[i] = isPossible[i - word.size()];
                }
                if (isPossible[i]) {
                    break;
                }
            }
        }
        
        return isPossible[s.size()];
    }
};