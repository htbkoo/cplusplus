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
    bool repeatedSubstringPattern(string s) {
        int sLength = s.size();
        for (int substrLength = 1; substrLength <= sLength / 2; substrLength++) {
            if (sLength % substrLength != 0) {
                continue;
            }
            if (canForm(s, substrLength)) {
                return true;
            }
        }
        return false;
    }
    
private:
    bool canForm(string& s, int substrLength) {
        return s == repeat(s.substr(0, substrLength), s.size() / substrLength);
    }

    // reference: https://stackoverflow.com/a/167810
    string repeat(string s, int n) {
        ostringstream os;
        for(int i = 0; i < n; i++)
            os << s;
        return os.str();
    }
};