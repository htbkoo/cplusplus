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
    string minRemoveToMakeValid(string s) {
        int open = 0;
        int closed = 0;
            
        for (auto ch: s) {
            if (ch == '(') {
                open++;
            } else if (ch == ')') {
                closed = min(open, closed + 1);
            }
        }
        
        string answer;
        
        int opened = 0;           
        for (auto ch: s) {
            bool shouldAddOpen = ch == '(' && closed > 0;
            bool shouldAddClose = ch == ')' && opened > 0;
            bool shouldAddCh = ch != '(' && ch != ')';
            
            if (shouldAddOpen) {
                answer += ch;
                opened++;
                closed--;
            } else if (shouldAddClose) {
                answer += ch;
                opened--;
            } else if (shouldAddCh) {
                answer += ch;
            }
        }
        
        return answer;
    }
};
