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
    bool checkIfPangram(string sentence) {
        unordered_set<char> chars(sentence.begin(), sentence.end());
            
        return chars.size() == 26;
    }
};

class FirstSolution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> chars;
        
        for (char ch: sentence) {
            chars.insert(ch);
        }
    
        return chars.size() == 26;
    }
};