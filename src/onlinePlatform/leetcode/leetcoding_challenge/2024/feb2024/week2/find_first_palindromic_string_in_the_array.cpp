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
    string firstPalindrome(vector<string>& words) {
        for (auto word: words) {
            if (isPalindromic(word)) {
                return word;
            }
        }
        return "";
    }

private:
    bool isPalindromic(string word) {
        int lo = 0;
        int hi = word.size() - 1;
        while (lo < hi) {
            if (word[lo] != word[hi]) {
                return false;
            }
            lo += 1;
            hi -= 1;
        }
        return true;
    }
};
