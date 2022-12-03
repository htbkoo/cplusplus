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
    string frequencySort(string s) {
        unordered_map<char, int> frequencies;
        
        for (char ch: s) {
            frequencies[ch]++;
        }
        
        vector<pair<int, char>> countCharPairs;
        for (auto& [ch, count]: frequencies) {
            countCharPairs.push_back(pair<int, char>{count, ch});
        }
        
        sort(countCharPairs.begin(), countCharPairs.end(), [](pair<int, char> pa, pair<int, char> pb){return pa.first > pb.first;});
        
        string answer;
        for (auto& [count, ch]: countCharPairs) {
            answer += string(count, ch);
        }
        
        return answer;
    }
};
