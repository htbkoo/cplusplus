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
    int longestPalindrome(string s) {
        unordered_map<char, int> counter;

        for (auto ch: s) {
            counter[ch]++;
        }

        int answer = 0;
        bool hasOdd = false;
        for (auto& [ch, count]: counter) {
            answer += count / 2 * 2;
            if (count % 2 != 0 && !hasOdd) {
                hasOdd = true;
                answer++;
            }
        }

        return answer;
     }
};

class WASolution {
public:
    int longestPalindrome(string s) {
        int answer = 0;

        for (int start = 0; start < s.size(); ++start) {
            for (int end = start; end < s.size(); ++end) {
                if (isPalindrome(s, start, end)) {
                    answer = max(answer, end - start + 1);
                }
            }
        }

        return answer;
    }

private:
    bool isPalindrome(string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }

        return true;
    }
};
