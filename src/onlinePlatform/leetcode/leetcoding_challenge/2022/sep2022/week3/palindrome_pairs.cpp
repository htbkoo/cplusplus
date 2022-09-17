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
        unordered_map<char, Trie> children;
        unordered_map<int, int> positions; 
        unordered_set<int> endsHere;         
        
        void addWord(int i, string word) {
            Trie* trie = this;
            for (int ch_idx = 0; ch_idx < word.size(); ch_idx++) {
                char ch = word[ch_idx];
                if (trie->children.count(ch) == 0) {
                    trie->children[ch] = Trie();
                }
                trie->positions[i] = ch_idx;
                trie = &(trie->children[ch]);
            }
            trie->endsHere.insert(i);
        }    
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        Trie trie;

        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            trie.addWord(i, word);
        }

        vector<vector<int>> answer;

        for (int i = 0; i < words.size(); i++) {
            Trie curr = trie;
            
            string word = words[i];
            for (int ch_idx = word.size() - 1; ch_idx >= 0 ; ch_idx--) {
                char ch = word[ch_idx];
                if (curr.children.count(ch) == 0) {
                    break;
                }                
                // TODO: investigate this
                Trie curr2 = curr.children[ch];
                curr = curr2;

                if (curr.endsHere.size() > 0) {
                    if (isPalindrome(word, ch_idx, word.size() - 1)) {
                        for (int j: curr.endsHere) {
                            answer.push_back({j, i});
                        }
                    }
                }
            }

            if (curr.positions.size() > 0) {
                for (auto const& [j, pos]: curr.positions) {
                    if (curr.endsHere.count(j) > 0) {                        
                        answer.push_back({j, i});
                    } else {
                        string anotherWord = words[j];
                        if (isPalindrome(anotherWord, 0, pos)) {
                            answer.push_back({i, j});
                        }
                    }
                }
                break;
            } else {
                for (int j: curr.endsHere) {
                    answer.push_back({i, j});
                }
            }
        }

        return answer;
    }

    bool isPalindrome(string word, int lo, int hi) {
        while (lo < hi) {
            if (word[lo] != word[hi]) {
                return false;
            }
            lo++;
            hi--;
        }

        return true;
    }
};

int main() {
    Solution soln;
    vector<string> words = {"abcd","dcba","lls","s","sssll"};
    soln.palindromePairs(words);
}