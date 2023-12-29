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

const int UNINITIALIZED = -1;

class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        memo = unordered_map<string, bool>();

        return isValid(s, 0, s.size() - 1, k);
    }

private:
    unordered_map<string, bool> memo;

    bool isValid(string& s, int i, int j, int k) {
        if (i >= j) {
            return true;
        }
        string key = to_string(i) + "_" + to_string(j) + "_" + to_string(k);

        if (memo.count(key) == 0) {
            if (s[i] == s[j]) {
                memo[key] = isValid(s, i + 1, j - 1, k);
            } else {
                memo[key] = k > 0 && (isValid(s, i + 1, j, k - 1) || isValid(s, i, j - 1, k - 1));
            }
        }

        return memo[key];
    }
};

class MLESolution {
public:
    bool isValidPalindrome(string s, int k) {
        memo = vector<vector<vector<int>>>();

        for (int i = 0; i <= s.size(); ++i) {
            memo.push_back(vector<vector<int>>());
            for (int j = 0; j <= s.size(); ++j) {
                memo[i].push_back(vector<int>(k + 1, UNINITIALIZED));
            }
        }

        return isValid(s, 0, s.size() - 1, k) == 1 ? true : false;
    }

private:
    vector<vector<vector<int>>> memo;

    int isValid(string& s, int i, int j, int k) {
        if (i >= j) {
            return true;
        }

        if (memo[i][j][k] == UNINITIALIZED) {
            if (s[i] == s[j]) {
                memo[i][j][k] = isValid(s, i + 1, j - 1, k);
            } else {
                memo[i][j][k] = 0;
                if (k > 0 && (isValid(s, i + 1, j, k - 1) || isValid(s, i, j - 1, k - 1))) {
                    memo[i][j][k] = 1;
                }
            }
        }

        return memo[i][j][k];
    }
};