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
    int partitionString(string s) {
        // TODO: what if s is empty?
        
        unordered_set<char> chars;
        
        int answer = 0;
        
        for (char ch: s) {
            if (chars.count(ch) > 0) {
                answer++;
                chars = unordered_set<char>();
            }
            chars.insert(ch);
        }
        
        return answer + 1;
    }
};
