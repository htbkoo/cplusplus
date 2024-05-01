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
    string reversePrefix(string word, char ch) {
        string answer = "";
        
        bool reversed = false;
        for (auto wordCh: word) {
            answer += wordCh;
            if (!reversed && wordCh == ch) {
                reversed = true;
                
                reverse(begin(answer), end(answer));
            }            
        }
        
        return answer;
    }
};
