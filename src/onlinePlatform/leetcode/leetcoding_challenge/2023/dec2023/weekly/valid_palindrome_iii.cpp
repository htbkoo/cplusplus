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

const int UNINITIALIZED = 1001;

class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        vector<vector<int>> memo = vector<vector<int>>();

        for (int i = 0; i < s.size(); ++i) {
            memo.push_back(vector<int>(s.size(), UNINITIALIZED));
        }

        for (int j = 0; j < s.size(); ++j) {
            for (int i = 0; i <= j; ++i) {
                memo[j][i] = 0;
            }
        }

        for (int x = 1; x < s.size(); ++x) {
            int j = 0;
            while (j < s.size() && (x + j) < s.size()) {
                int i = x + j;
                if (s[i] == s[j]) {
                    memo[j][i] = memo[j + 1][i - 1];
                } else {
                    memo[j][i] = 1 + min(
                        memo[j][i - 1],
                        memo[j + 1][i]
                    );
                }
                j++;
            }
        }


        return memo[0][s.size() - 1] <= k;
    }
};

class TopDownSolution {
public:
    bool isValidPalindrome(string s, int k) {
        memo = vector<vector<int>>();

        for (int i = 0; i <= s.size(); ++i) {
            memo.push_back(vector<int>(s.size() + 1, UNINITIALIZED));
        }

        return findMin(s, 0, s.size() - 1) <= k;
    }

private:
    vector<vector<int>> memo;

    int findMin(string& s, int i, int j) {
        if (i >= j) {
            return 0;
        }

        if (memo[i][j] == UNINITIALIZED) {
            if (s[i] == s[j]) {
                memo[i][j] = findMin(s, i + 1, j - 1);
            } else {
                memo[i][j] = 1 + min(
                    findMin(s, i + 1, j),
                    findMin(s, i, j - 1)
                );

            }
        }

        return memo[i][j];
    }
};

class TLESolution {
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

int main() {
    Solution soln;

    // cout << soln.isValidPalindrome("abcdeca", 2) << endl;
    cout << soln.isValidPalindrome("aaabaabaa", 1) << endl;

    return 0;
}