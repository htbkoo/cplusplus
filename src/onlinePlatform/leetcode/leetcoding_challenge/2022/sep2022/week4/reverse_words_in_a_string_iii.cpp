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
    string reverseWords(string s) {
        vector<char> answer;

        int prev = 0;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == ' ') {
                for (int j = i - 1; j >= prev; j--) {
                    answer.push_back(s[j]);
                }
                answer.push_back(' ');
                prev = i + 1;
            }
        }

        if (prev < s.size()) {
            for (int j = s.size() - 1; j >= prev; j--) {
                answer.push_back(s[j]);
            }
        }

        return string(answer.begin(), answer.end());
    }
};

int main() {
    Solution soln;    
    cout << soln.reverseWords("God Ding") << endl;

    return 0;
}