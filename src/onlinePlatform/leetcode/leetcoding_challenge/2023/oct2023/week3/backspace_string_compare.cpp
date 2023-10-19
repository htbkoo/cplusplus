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
    bool backspaceCompare(string s, string t) {
        return compute(s) == compute(t);
    }
    
private:
    string compute(string& s) {
        vector<char> stack;
        for (auto ch: s) {
            if (ch == '#') {
                if (stack.size() > 0) {
                    stack.pop_back();
                }
            } else {
                stack.push_back(ch);
            }
        }
        return string(stack.begin(), stack.end());
    }
};