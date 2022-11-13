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
    string reverseWords(string s) {
        vector<string> words;
        vector<char> curr;
        for (char ch: s) {
            if (ch != ' ') {
                curr.push_back(ch);
            } else {
                if (curr.size() > 0) {
                    words.push_back(string(curr.begin(), curr.end()));
                    curr = vector<char>();
                }                
            }
        }
        
        if (curr.size() > 0) {
            words.push_back(string(curr.begin(), curr.end()));
        }
        
        if (words.size() == 0) {
            return "";
        }
        
        string answer = words[words.size() - 1];
        for (int i = words.size() - 2; i >= 0; i--) {
            answer += " " + words[i];
        }
        
        return answer;
    }
};
