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
        unordered_map<char, unordered_set<char>> equals;
        unordered_map<char, unordered_set<char>> notEquals;

        parents = unordered_map<char, char>();

        int EQUATION_SIZE = 4;

        for (auto equation: equations) {
            if (equation.size() != EQUATION_SIZE) {
                throw invalid_argument("invalid equation: " + equation);
            }
            
            char a = equation[0];
            char b = equation[3];

            parents[a] = a;
            parents[b] = b;
            
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

        for (auto &[ch, neighbours]: equals) {
            for (char nextCh: neighbours) {
                unionDsu(ch, nextCh);
            }
        }

        for (auto &[ch, neighbours]: notEquals) {
            for (char nextCh: neighbours) {
                if (findParent(ch) == findParent(nextCh)) {
                    return false;
                }
            }
        }

        return true;
    }

    char findParent(char ch) {
        if (parents.count(ch) == 0) {
            parents[ch] = ch;
        }
        // path compression
        if (parents[ch] != ch) {
            parents[ch] = findParent(parents[ch]);
        }
        return parents[ch];
    }

    void unionDsu(char ch1, char ch2) {
        ch1 = findParent(ch1);
        ch2 = findParent(ch2);
        if (parents[ch1] == parents[ch2]) {
            return;
        }
        parents[ch2] = parents[ch1];
    }

private:
    unordered_map<char, char> parents;
};

int main() {
    Solution soln;
    
    // vector<string> equations1 = {"a==b", "b!=a"};
    // cout << soln.equationsPossible(equations1) << endl;
    // vector<string> equations2 = {"a==b", "b==a"};
    // cout << soln.equationsPossible(equations2) << endl;
    vector<string> equations3 = {"a==b","c==d","a==c","a!=d"};
    cout << soln.equationsPossible(equations3) << endl;

    return 0;
}