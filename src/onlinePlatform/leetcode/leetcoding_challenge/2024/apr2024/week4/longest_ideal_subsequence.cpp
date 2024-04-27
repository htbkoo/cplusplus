#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <limits>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iterator>
#include <sstream>
#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text

const int UNINITIALIZED = -1;

class Solution {
public:
    int longestIdealString(string s, int k) {
        int CHARSET_SIZE = 26;

        vector<int> longest(CHARSET_SIZE, 0);

        for (int i = 0; i < s.size(); ++i) {
            auto o = ord(s[i]);

            int best = longest[o];
            for (int j = max(0, o - k); j < min(CHARSET_SIZE, o + k + 1); ++j) {
                best = max(best, 1 + longest[j]);
            }
            longest[o] = best;
        }

        int answer = 0;
        for (int i = 0; i < CHARSET_SIZE; ++i) {
            answer = max(answer, longest[i]);
        }

        return answer;
    }

private:
    int ord(char ch) {
        return ch - 'a';
    }
};

class FirstSolution {
public:
    int longestIdealString(string s, int k) {
        int CHARSET_SIZE = 26;

        vector<int> longest(CHARSET_SIZE, 0);

        for (int i = 0; i < s.size(); ++i) {
            vector<int> prev = vector<int>(begin(longest), end(longest));

            auto o = ord(s[i]);

            for (int j = max(0, o - k); j < min(CHARSET_SIZE, o + k + 1); ++j) {
                longest[o] = max(longest[o], 1 + prev[j]);
            }
        }

        int answer = 0;
        for (int i = 0; i < CHARSET_SIZE; ++i) {
            answer = max(answer, longest[i]);
        }

        return answer;
    }

private:
    int ord(char ch) {
        return ch - 'a';
    }
};

class MLESolution {
public:
    int longestIdealString(string s, int k) {
        int CHARSET_SIZE = 26;
        memo = vector<vector<int>>();
        for (int i = 0; i < s.size(); ++i) {
            memo.push_back(vector<int>(CHARSET_SIZE, UNINITIALIZED));
        }

        int answer = 0;
        for (int i = 0; i < s.size(); ++i) {
            answer = max(answer, 1 + findLongest(s, k, i + 1, ord(s[i])));
        }

        return answer;
    }

private:
    vector<vector<int>> memo;

    int findLongest(string s, int k, int i, int prev) {
        if (i >= s.size()) {
            return 0;
        }

        if (memo[i][prev] == UNINITIALIZED) {
            memo[i][prev] = findLongest(s, k, i + 1, prev);

            if (abs(ord(s[i]) - prev) <= k) {
                memo[i][prev] = max(
                    memo[i][prev],
                    1 + findLongest(s, k, i + 1, ord(s[i]))
                );
            }
        }

        return memo[i][prev];
    }

    int ord(char ch) {
        return ch - 'a';
    }
};
