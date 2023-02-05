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
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) {
            return {};
        }
        
        unordered_map<char, int> pCounter;
        for (char ch: p) {
            pCounter[ch]++;
        }
        
        unordered_map<char, int> sCounter;
        for (int i = 0; i < p.size() - 1; i++) {
            char ch = s[i];
            sCounter[ch]++;
        }
        
        vector<int> answer;
        for (int i = p.size() - 1; i < s.size(); i++) {
            char ch = s[i];
            int beginIdx = i - (p.size() - 1);
            sCounter[ch]++;
            if (pCounter == sCounter) {
                answer.push_back(beginIdx);
            }
            
            char prevCh = s[beginIdx];
            sCounter[prevCh]--;
            if (sCounter[prevCh] == 0) {
                sCounter.erase(prevCh);
            }
        }
        
        return answer;
    }    
};