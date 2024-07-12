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
    int maximumGain(string s, int x, int y) {
        vector<char> arr;
        for (auto ch: s) {
            arr.push_back(ch);
        }
        
        vector<pair<string, int>> seq = (x >= y) ? (vector<pair<string, int>>{pair{"ab", x}, pair{"ba", y}}) : (vector<pair<string, int>>{pair{"ba", y}, pair{"ab", x}});
        
        auto [score, remain] = remove(arr, seq[0]);
        score += remove(remain, seq[1]).first;
        return score;
    }
    
private:
    pair<int, vector<char>> remove(vector<char>& arr, pair<string, int> p) {
        auto [seq, add] = p;
        
        int score = 0;
        vector<char> remain;
        for (auto ch: arr) {
            if (remain.size() > 0 && ((string() + remain.back() + ch) == seq)) {
                score += add;
                remain.pop_back();
            } else {
                remain.push_back(ch);
            }
        }
            
        return pair{score, remain};
    }
};
