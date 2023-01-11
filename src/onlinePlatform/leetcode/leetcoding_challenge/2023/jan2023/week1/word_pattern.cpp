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
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mapping;
        unordered_map<string, char> reversedMap;
        
        vector<string> words = split(s);
        
        if (words.size() != pattern.size()) {
            return false;
        }
        
        for (int i = 0; i < words.size(); i++) {
            char ch = pattern[i];
            string word = words[i];

            bool m = mapping.count(ch) > 0 && mapping[ch] != word;
            bool r = reversedMap.count(word) > 0 && reversedMap[word] != ch;

            if (m || r) {
                return false;
            }
            mapping[ch] = word;
            reversedMap[word] = ch;
        }
        
        return true;
    }
    
    vector<string> split(string& s) {
        vector<string> words;

        istringstream iss(s);
        string word;
        
        while (iss >> word) {
            words.push_back(word);
        }
        return words;
    }
};

class FirstSolution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mapping;
        unordered_map<string, char> reversedMap;
        
        vector<string> words = split(s);
        
        if (words.size() != pattern.size()) {
            return false;
        }
        
        for (int i = 0; i < words.size(); i++) {
            char ch = pattern[i];
            string word = words[i];

            bool m = mapping.count(ch) > 0 && mapping[ch] != word;
            bool r = reversedMap.count(word) > 0 && reversedMap[word] != ch;

            if (m || r) {
                return false;
            }
            mapping[ch] = word;
            reversedMap[word] = ch;
        }
        
        return true;
    }
    
    vector<string> split(string& s) {
        vector<string> words;
        istringstream iss(s);
        
        while (iss) {
            string sub;
            iss >> sub;
            if (sub.size() > 0) {
                words.push_back(sub);
            } else {
                return words;
            }
        }
        return words;
    }
};

int main() {
    Solution soln;
    cout << (soln.wordPattern("abba", "dog cat cat dog") ? "true" : "false") << endl;
}