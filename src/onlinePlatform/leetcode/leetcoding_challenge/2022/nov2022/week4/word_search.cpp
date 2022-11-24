#include <algorithm>
#include <cmath>
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


vector<pair<int, int>> DIRECTIONS = {
    pair{-1, 0},
    pair{1, 0},
    pair{-0, -1},
    pair{0, 1}
};

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int height = board.size();
        int width = board[0].size();
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                set<pair<int, int>> used;
                if (search(board, word, used, y, x)) {
                    return true;
                }
            
            }   
        }
        return false;
    }
    
private:
    bool search(vector<vector<char>>& board, string word, set<pair<int, int>>& used, int y, int x) {
        if (used.size() == word.size()) {
            return true;
        }
        
        int height = board.size();
        int width = board[0].size();
        bool isWithinBoundary = 0 <= y && y < height && 0 <= x && x < width;
        
        if (!isWithinBoundary) {
            return false;
        }
        
        if (word[used.size()] != board[y][x]) {
            return false;
        }
        
        pair<int, int> coords = pair<int, int>{y, x};
        if (used.count(coords) > 0) {
            return false;
        }        
        
        used.insert(coords);
        
        for (auto& [dy, dx]: DIRECTIONS) {
            int ny = y + dy;
            int nx = x + dx;
            if (search(board, word, used, ny, nx)) {
                return true;
            }
        }
        
        used.erase(coords);
        
        return false;
    }   
};