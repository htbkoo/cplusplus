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
    int firstUniqChar(string s) {
        unordered_map<char, int> positions;
        unordered_set<char> repeated;

        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if (repeated.count(ch) > 0) {
                continue;
            }

            if (positions.count(ch) > 0) {
                positions.erase(ch);
                repeated.insert(ch);
                continue;
            }

            positions[ch] = i;
        }

        if (positions.size() == 0) {
            return -1;
        }

        int answer = s.size();
        for (auto& [ch, pos]: positions) {
            answer = min(answer, pos);
        }

        return answer;
    }
};
