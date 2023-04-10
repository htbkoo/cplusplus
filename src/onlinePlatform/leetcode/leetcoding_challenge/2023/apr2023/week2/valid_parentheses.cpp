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
    bool isValid(string s) {
        unordered_map<char, char> conjugates = {{'}', '{'}, {')', '('}, {']','['}};
        
        vector<char> stack;
        
        for (auto ch: s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                stack.push_back(ch);
            } else {
                if (stack.size() == 0) {
                    return false;
                } 
                char prev = stack.back();
                stack.pop_back();
                if (prev != conjugates[ch]) {
                    return false;
                }                
            }
        }
        
        return stack.size() == 0;
    }
};