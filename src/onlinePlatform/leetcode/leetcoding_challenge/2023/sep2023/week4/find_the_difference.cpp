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
    char findTheDifference(string s, string t) {
        unordered_map<char, int> counter;
        for (auto ch: t) {
            counter[ch]++;
        }
        for (auto ch: s) {
            counter[ch]--;
        }
        
        for (auto& [ch, count]: counter) {
            if (count > 0) {
                return ch;
            }
        }
        // TODO: throw error here
        return ' ';
    }
};
