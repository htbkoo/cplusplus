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
    bool wordPatternMatch(string pattern, string s) {
        mapping = unordered_map<char, string>();
        used = unordered_set<string>();

        return canMatch(pattern, s, 0, 0);
    }

private:
    unordered_map<char, string> mapping;
    unordered_set<string> used;

    bool canMatch(string& pattern, string& s, int i, int j) {
        if (i == pattern.size() && j == s.size()) {
            return true;
        }

        if (i == pattern.size() || j == s.size()) {
            return false;
        }

        char ch = pattern[i];

        if (mapping.count(ch) > 0) {
            string mapped = mapping[ch];
            for (int m = 0; m < mapped.size(); ++m) {
                if (j + m >= s.size() || s[j + m] != mapped[m]) {
                    return false;
                }
            }
            return canMatch(pattern, s, i + 1, j + mapped.size());
        }

        for (int nextJ = j + 1; nextJ <= s.size(); ++nextJ) {
            int count = nextJ - j;

            string ss = s.substr(j, count);

            if (used.count(ss) == 0) {
                mapping[ch] = ss;
                used.insert(ss);

                if (canMatch(pattern, s, i + 1, nextJ)) {
                    return true;
                }

                used.erase(ss);
                mapping.erase(ch);
            }
        }

        return false;
    }
};

class WASolution {
public:
    bool wordPatternMatch(string pattern, string s) {
        mapping = unordered_map<char, string>();
        used = unordered_set<string>();

        return canMatch(pattern, s, 0, 0);
    }

private:
    unordered_map<char, string> mapping;
    unordered_set<string> used;

    bool canMatch(string& pattern, string& s, int i, int j) {
        if (i == pattern.size() && j == s.size()) {
            return true;
        }

        if (i == pattern.size() || j == s.size()) {
            return false;
        }

        for (int nextJ = j + 1; nextJ <= s.size(); ++nextJ) {
            char ch = pattern[i];
            if (mapping.count(ch) > 0) {
                string mapped = mapping[ch];
                for (int m = 0; m < mapped.size(); ++m) {
                    if (j + m >= s.size() || s[j + m] != mapped[m]) {
                        return false;
                    }
                }
                return canMatch(pattern, s, i + 1, j + mapped.size());
            } else {
                int count = nextJ - j;

                string ss = s.substr(j, count);

                if (used.count(ss) == 0) {
                    used.insert(ss);

                    if (canMatch(pattern, s, i + 1, nextJ)) {
                        return true;
                    }

                    used.erase(ss);
                }

                return canMatch(pattern, s, i, j + 1);
            }
        }

        return false;
    }
};
