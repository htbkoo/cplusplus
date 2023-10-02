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
    bool winnerOfGame(string colors) {
        unordered_map<char, int> counter;
        
        for (int i = 1; i < colors.size() - 1; ++i) {
            if (colors[i] == colors[i - 1] && colors[i] == colors[i + 1]) {
                counter[colors[i]]++;
            }
        }
        
        return counter['A'] > counter['B'];
    }
};

