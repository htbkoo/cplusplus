#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <limits>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <iterator>
#include <sstream>
#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text

string KEY_SEPARATOR = "_";

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        
        for (string str: strs) {
            string key = asKey(str);
            if (groups.count(key) == 0) {
                groups[key] = vector<string>();
            }
            groups[key].push_back(str);            
        }
        
        vector<vector<string>> answer;
        for (auto &[key, anagrams]: groups) {
            answer.push_back(anagrams);
        }
        return answer;
    }
    
    string asKey(string str) {
        map<char, int> counter;
        
        for (char ch: str) {
            if (counter.count(ch) == 0) {
                counter[ch] = 0;
            }
            counter[ch]++;
        }
        
        string key = "";
        for (auto &[ch, count]: counter) {
            key += ch + KEY_SEPARATOR + to_string(count);
        }
        return key;
    }
};