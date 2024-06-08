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
    long long numberOfSubstrings(string s) {
        unordered_map<char, int> counter;

        long long answer = 0;
        for (auto ch: s) {
            counter[ch]++;
            answer += counter[ch];
        }

        return answer;
    }
};
