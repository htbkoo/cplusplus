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
    unordered_map<char, Trie> *children;
    unordered_set<string> wordsEndHere;
    
        
    Trie() {
        children = new unordered_map<char, Trie>();
    }
    
    void addWord(string word) {
        Trie *curr = this;
        
        for (char ch: word) {
            if (curr->children->count(ch) == 0) {                
                curr->children->insert(pair<char, Trie>{ch, Trie()});
            }            
            curr = &(curr->children->at(ch));
        }
        
        curr->wordsEndHere.insert(word);
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        
        for (string word: words) {
            trie.addWord(word);
        }

        unordered_set<string> wordsSet = unordered_set<string>(words.begin(), words.end());
        for (int y = 0; y < board.size(); y++) {
            for (int x = 0; x < board[0].size(); x++) {
                set<pair<int, int>> visited;
                dfs(board, wordsSet, trie, visited, y, x, "");
            }
        }

        return vector<string>(answer.begin(), answer.end());
    }

private:
    vector<pair<int, int>> DIRECTIONS = {
        pair<int, int>{-1, 0},
        pair<int, int>{1, 0},
        pair<int, int>{0, -1},
        pair<int, int>{0, 1},
    };
    unordered_set<string> answer;

    void dfs(vector<vector<char>>& board, unordered_set<string>& words, Trie& trie, set<pair<int, int>>& visited, int y, int x, string path) {
        bool isWithinBoundary = 0 <= y && y < board.size() && 0 <= x && x < board[0].size();
        if (!isWithinBoundary) {
            return;
        }

        char ch = board[y][x];
        if (trie.children->count(ch) == 0) {
            return;
        }

        pair<int, int> coords = pair<int, int>{y, x};
        if (visited.count(coords) > 0) {
            return;
        }
        visited.insert(coords);

        string newPath = path + ch;
        if (words.count(newPath) > 0) {
            answer.insert(newPath);
        }

        for (auto& [dy, dx]: DIRECTIONS) {
            int ny = y + dy;
            int nx = x + dx;
            dfs(board, words, trie.children->at(ch), visited, ny, nx, newPath);            
        }

        visited.erase(coords);
    }
};

/*
class Trie {
public:
    unique_ptr<unordered_map<char, Trie>> children;
    unordered_set<string> wordsEndHere;
        
    Trie() {
        children.reset(new unordered_map<char, Trie>());
    }
    
    void addWord(string word) {
        unique_ptr<unordered_map<char, Trie>> curr(this);
        
        for (char ch: word) {
            if (curr->count(ch) == 0) {
                (*curr)[ch] = unordered_map<char, Trie>();
            }
            curr.reset
        }
        
    }
};
*/

int main() {
    Solution soln;
    vector<vector<char>> board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    vector<string> words = {"oath","pea","eat","rain"};
    auto answer = soln.findWords(board, words);
    for (auto word: answer) {
        cout << word << endl;
    }
}