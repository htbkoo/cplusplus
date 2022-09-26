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
#include <string>
#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int EQUATION_SIZE = 4;

        unordered_set<char> allChars;
        
        for (auto equation: equations) {
            if (equation.size() != EQUATION_SIZE) {
                throw invalid_argument("invalid equation: " + equation);
            }
            
            char a = equation[0];
            char b = equation[3];

            allChars.insert(a);
            allChars.insert(b);
            
            if (equation[1] == '=') {
                equals[a].insert(b);
                equals[b].insert(a);
            } else if (equation[1] == '!') {
                notEquals[a].insert(b);
                notEquals[b].insert(a);
            } else {
                throw invalid_argument("invalid equation: " + equation);
            }            
        }

        for (char ch: allChars) {
            if (!dfs(ch, unordered_set<char>(),unordered_set<char>{ch}, unordered_set<char>())) {
                return false;
            }
        }

        return true;
    }

    bool dfs(
        char ch, 
        unordered_set<char> visited, 
        unordered_set<char> currEqual, 
        unordered_set<char> currNotEqual
    ) {
        if (visited.count(ch) > 0) {
            return true;
        }
        visited.insert(ch);



    }

private:
    unordered_map<char, unordered_set<char>> equals;
    unordered_map<char, unordered_set<char>> notEquals;
};

int main() {
    Solution soln;
    

    return 0;
}