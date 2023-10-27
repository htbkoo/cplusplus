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

const char SEPARATOR = '#';

class Solution {
public:
    string longestPalindrome(string s) {
        return findLongest(makeOddLength(s));
    }
    
private:
    string findLongest(string s) {
        int n = s.size();
        s = "^" + s + "$";
        vector<int> p(n + 2);
        
        int largestIdx = 1;
        
        int l = 1, r = 1;
        for (int i = 1; i <= n; ++i) {
            p[i] = max(0, min(r - i, p[l + (r - i)]));
            while (s[i - p[i]] == s[i + p[i]]) {
                p[i]++;
            }
            if (i + p[i] > r) {
                l = i - p[i];
                r = i + p[i];
            }
            if (p[i] > p[largestIdx]) {
                largestIdx = i;
            }
        }
        
        int start = largestIdx - (p[largestIdx] - 1);
        int size = 2 * p[largestIdx] - 1;
        string answer = s.substr(start, size);
        
        return removeSeparator(answer);
    }
    
    string makeOddLength(string s) {
        string t;
        t += SEPARATOR;
        for (char ch: s) {
            t += ch;
            t += SEPARATOR;
        }
        return t;
    }
    
    string removeSeparator(string s) {
        string answer = "";
        for (char ch: s) {
            if (ch != SEPARATOR) {
                answer += ch;
            }
        }
        return answer;
    }
};

int main() {
    Solution soln;

    cout << soln.longestPalindrome("babad") << endl;

    return 0;
}