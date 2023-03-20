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
        isWord = false;
    }
    
    void addWord(string word) {
        auto curr = this;
        for (char ch: word) {
            if (curr->children.count(ch) == 0) {
                curr->children[ch] = new Trie();
            }
            curr = curr->children[ch];
        }
        curr->isWord = true;
    }
    
    bool search(string word, int idx = 0) {
        char ch = word[idx];
        
        if (ch == '.') {            
            for (auto& [_, child]: children) {
                if (idx == word.size() - 1) {
                    if (child -> isWord) {
                        return true;
                    }
                } else {
                    if (child->search(word, idx + 1)) {
                        return true;
                    }
                }
            }
        } else {
            if (children.count(ch) == 0) {
                return false;
            }
            auto child = children[ch];
            if (idx == word.size() - 1) {
                return child->isWord;
            } else {
                return child->search(word, idx + 1);
            }
        }
        
        return false;
    }
    
private:
    unordered_map<char, Trie*> children;
    bool isWord;
};

class WordDictionary {
public:
    WordDictionary() {
        trie = new Trie();
    }
    
    void addWord(string word) {
        trie->addWord(word);
    }
    
    bool search(string word) {
        return trie->search(word);
    }

private:
    Trie* trie;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
