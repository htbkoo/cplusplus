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
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0, j = 0;
        
        vector<int> stack;
        while (j < popped.size()) {
            if (stack.size() > 0 && stack.back() == popped[j]) {
                stack.pop_back();
                j++;
            } else {
                if (i < pushed.size()) {
                    stack.push_back(pushed[i]);
                    i++;
                } else {
                    return false;
                }
            }
        }
        
        return true;
    }
};