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
    string mergeAlternately(string word1, string word2) {
        string answer = "";
        
        int i = 0, j = 0;
        while (i < word1.size() || j < word2.size()) {
            if (i < word1.size()) {
                answer += word1[i];
                i++;
            }
            if (j < word2.size()) {
                answer += word2[j];
                j++;
            }            
        }
        
        return answer;
    }
};