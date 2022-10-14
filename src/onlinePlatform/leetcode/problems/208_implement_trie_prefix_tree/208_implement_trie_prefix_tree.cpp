#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

const char WORD_END_CH = '#';

class Trie {    
    unordered_map<char, Trie> *children;
    bool endsHere;

public:
    Trie() {
        children = new unordered_map<char, Trie>();
        endsHere = false;
    }
    
    void insert(string word) {
        Trie* curr = this;
        for (char ch: word) {
            unordered_map<char, Trie> &child = *(curr->children);
            if (child.count(ch) == 0) {
                child[ch] = Trie();
            }
            curr = &child[ch];
        }
        curr->endsHere = true;
    }
    
    bool search(string word) {
        Trie* curr = this;
        for (char ch: word) {
            unordered_map<char, Trie> &child = *(curr->children);
            if (child.count(ch) == 0) {
                return false;
            }
            curr = &child[ch];
        }
        return curr->endsHere;
    }
    
    bool startsWith(string prefix) {
        Trie* curr = this;
        for (char ch: prefix) {
            unordered_map<char, Trie> &child = *(curr->children);
            if (child.count(ch) == 0) {
                return false;
            }
            curr = &child[ch];
        }
        return true;
    }
};

int main() {
    Trie* obj = new Trie();

    string word = "apple";
    obj->insert(word);
    cout << obj->search(word) << endl;
    cout << obj->search("app") << endl;
    cout << obj->startsWith("app") << endl;
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */