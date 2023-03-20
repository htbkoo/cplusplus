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

class Trie {
public:
    Trie() {
        isEnd = false;
    }
    
    void insert(string word) {
        words.insert(word);
        
        auto curr = this;
        for (char ch: word) {
            if (curr->children.count(ch) == 0) {
                curr->children[ch] = new Trie();
            }
            curr = curr->children[ch];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        return words.count(word) > 0;
    }
    
    bool startsWith(string prefix) {        
        auto curr = this;
        for (char ch: prefix) {
            if (curr->children.count(ch) == 0) {
                return false;
            }
            curr = curr->children[ch];
        }
        return true;
    }

private:
    unordered_set<string> words;
    unordered_map<char, Trie*> children;
    bool isEnd;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
