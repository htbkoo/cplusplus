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
    string makeGood(string s) {
        vector<char> stack;
        
        for (char ch: s) {
            if (stack.size() > 0 && isBad(stack.back(), ch)) {
                stack.pop_back();
            } else {
                stack.push_back(ch);
            } 
        }
        
        return string(stack.begin(), stack.end());
    }
    
    bool isBad(char ch1, char ch2) {
        return tolower(ch1) == tolower(ch2) && ch1 != ch2;
    }
};