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
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int right = 0;
        int left = 0;

        unordered_map<char, int> counter;

        int answer = 0;
        while (right < s.size()) {
            if (counter.size() <= 2) {
                counter[s[right]]++;
                right++;
            } else {
                counter[s[left]]--;
                if (counter[s[left]] == 0) {
                    counter.erase(s[left]);
                }
                left++;
            }

            if (counter.size() <= 2) {
                answer = max(answer, right - left);
            }
        }

        return answer;
    }
};