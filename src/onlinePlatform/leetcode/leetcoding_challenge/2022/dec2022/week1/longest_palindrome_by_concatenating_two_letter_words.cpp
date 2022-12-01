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


unordered_set<char> VOWELS = unordered_set<char>{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

class Solution {
public:
    bool halvesAreAlike(string s) {
        if (s.size() % 2 != 0) {
            throw invalid_argument("s has odd size");
        }
        
        return getCountVoewls(s, 0, s.size() / 2 - 1) == getCountVoewls(s, s.size() / 2, s.size() - 1);
    }
    
private:
    int getCountVoewls(string& s, int from, int to) {
        int count = 0;
        for (int i = from; i <= to; i++) {
            char ch = s[i];
            if (VOWELS.count(ch) > 0) {
                count++;
            }
        }
        return count;
    }
};