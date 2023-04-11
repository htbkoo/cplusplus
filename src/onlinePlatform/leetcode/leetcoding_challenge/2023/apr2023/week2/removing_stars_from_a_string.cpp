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
    string removeStars(string s) {
        vector<char> stack;
        
        for (auto ch: s) {
            if (ch == '*') {
                // TODO: handle invalid input, i.e. when stack is empty
                stack.pop_back();
            } else {
                stack.push_back(ch);
            }
        }
        
        return string(stack.begin(), stack.end());
    }
};
