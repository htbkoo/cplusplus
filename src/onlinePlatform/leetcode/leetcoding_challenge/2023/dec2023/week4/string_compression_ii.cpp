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
    int getLengthOfOptimalCompression(string s, int k) {
        memo = unordered_map<string, int>();

        return findMin(s, 0, k, "", 0);
    }

private:
    string SEPARATOR = "_";
    unordered_map<string, int> memo;

    int findMin(string& s, int i, int k, string ch, int length) {
        if (i >= s.size()) {
            return getCompressedLength(ch, length);
        }

        string key = to_string(i) + SEPARATOR + to_string(k) + SEPARATOR + ch + SEPARATOR + to_string(length);
        if (memo.count(key) == 0) {
            if (s.substr(i, 1) == ch) {
                memo[key] = findMin(s, i + 1, k, ch, length + 1);
            } else {
                memo[key] = getCompressedLength(ch, length) + findMin(s, i + 1, k, s.substr(i, 1), 1);
            }

            if (k > 0) {
                memo[key] = min(
                    memo[key],
                    findMin(s, i + 1, k - 1, ch, length)
                );
            }
        }

        return memo[key];
    }

    int getCompressedLength(string ch, int length) {
        if (length == 0) {
            return 0;
        } else if (length == 1) {
            return ch.size();
        } else {
            return ch.size() + to_string(length).size();
        }
    }

};

class WASolution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        memo = unordered_map<string, int>();

        return findMin(s, 0, k, "", 0);
    }

private:
    string SEPARATOR = "_";
    unordered_map<string, int> memo;

    int findMin(string& s, int i, int k, string ch, int length) {
        if (i >= s.size()) {
            return getCompressedLength(ch, length);
        }

        string key = to_string(i) + SEPARATOR + to_string(k) + SEPARATOR + ch + SEPARATOR + to_string(length);
        if (memo.count(key) == 0) {
            if (s.substr(i, 1) == ch) {
                memo[key] = findMin(s, i + 1, k, ch, length + 1);
            } else {
                memo[key] = getCompressedLength(ch, length) + findMin(s, i + 1, k, s.substr(i, 1), 1);
            }

            if (k > 0) {
                memo[key] = min(
                    memo[key],
                    findMin(s, i + 1, k - 1, ch, length)
                );
            }
        }

        return memo[key];
    }

    int getCompressedLength(string ch, int length) {
        if (length == 0) {
            return 0;
        } else {
            return ch.size() + to_string(length).size();
        }
    }

};

int main() {
    Solution soln;
    cout << soln.getLengthOfOptimalCompression("abc", 2) << endl;
    return 0;
}