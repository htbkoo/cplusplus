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
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> longest;
        for (int i = 0; i < s.size(); i++) {
            longest.push_back(vector<int>(s.size(), 0));
            longest[i][i] = 1;
        }
        
        for (int d = 1; d < s.size(); d++) {
            for (int begin = 0; begin < s.size(); begin++) {
                int end = begin + d;
                if (end >= s.size()) {
                    break;
                }
                
                longest[begin][end] = max(
                    longest[begin + 1][end],
                    longest[begin][end - 1]
                );
                
                if (s[begin] == s[end]) {
                    longest[begin][end] = max(
                        longest[begin][end],
                        longest[begin + 1][end - 1] + 2
                    );
                }
            }
        }
        
        return longest[0][s.size() - 1];
    }
};