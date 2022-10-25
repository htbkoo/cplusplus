#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <limits>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <iterator>
#include <sstream>
#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text


class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int w1 = 0;
        int c1 = 0;
        int w2 = 0;
        int c2 = 0;
        
        while (w1 < word1.size() && w2 < word2.size()) {
            if (c1 >= word1[w1].size()) {
                w1++;
                c1 = 0;
            }
            if (c2 >= word2[w2].size()) {
                w2++;
                c2 = 0;
            }
            
            if (w1 >= word1.size() && w2 >= word2.size()) {
                return true;
            }            
            if (w1 >= word1.size() || w2 >= word2.size()) {
                return false;
            }
            
            if (word1[w1][c1] != word2[w2][c2]) {
                return false;
            }
            
            c1++;
            c2++;
        }
        
        return true;
    }
};