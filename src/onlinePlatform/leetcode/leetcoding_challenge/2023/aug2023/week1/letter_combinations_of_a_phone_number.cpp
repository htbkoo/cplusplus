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
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }
        
        unordered_map<char, vector<string>> MAPPING = {
            {'2', {"a", "b", "c"}},
            {'3', {"d", "e", "f"}},
            {'4', {"g", "h", "i"}},
            {'5', {"j", "k", "l"}},
            {'6', {"m", "n", "o"}},
            {'7', {"p", "q", "r", "s"}},
            {'8', {"t", "u", "v"}},
            {'9', {"w", "x", "y", "z"}}
        };
        
        vector<string> answer;
        vector<pair<string, int>> q{pair{"", 0}};
        
        while (q.size() > 0) {
            vector<pair<string, int>> prev = q;
            q = vector<pair<string, int>>();
            
            for (auto& [head, pos]: prev) {
                if (pos >= digits.size()) {
                    answer.push_back(head);
                } else {
                    for (auto ch: MAPPING[digits[pos]]) {
                        q.push_back(pair{head + ch, pos + 1});
                    }
                }
            }
        }
        
        return answer;
    }
};
