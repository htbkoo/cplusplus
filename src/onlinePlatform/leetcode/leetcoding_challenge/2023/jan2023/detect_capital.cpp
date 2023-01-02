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
    bool detectCapitalUse(string word) {
        if (word.size() == 0) {
            throw invalid_argument("word is empty");
        }
        
        bool isAllCapital = isCapital(word[0]);
        bool isTailNonCapital = true;        
        for (int i = 1; i < word.size(); i++) {
            char ch = word[i];
            if (isCapital(ch)) {
                isTailNonCapital = false;
            } else {
                isAllCapital = false;
            }
        }
        
        return isAllCapital || isTailNonCapital;
    }
    
private:
    bool isCapital(char ch) {
        return 'A' <= ch && ch <= 'Z';
    }
};