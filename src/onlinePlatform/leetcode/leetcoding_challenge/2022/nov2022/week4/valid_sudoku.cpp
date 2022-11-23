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


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        char EMPTY = '.';
        // validate rows
        for (int r = 0; r < board.size(); r++) {
            vector<char> v;
            for (int c = 0; c < board[0].size(); c++) {
                if (board[r][c] == EMPTY) {
                    continue;
                }
                v.push_back(board[r][c]);
            }
            
            if (!isValid(v)) {
                return false;
            }
        }

        // validate cols
        for (int c = 0; c < board[0].size(); c++) {
            vector<char> v;
            for (int r = 0; r < board.size(); r++) {
                if (board[r][c] == EMPTY) {
                    continue;
                }
                v.push_back(board[r][c]);
            }
            
            if (!isValid(v)) {
                return false;
            }
        }

        // validate boxes
        // TODO: improve this
        int NUM_BOXES = 3;
        int BOX_SIZE = 3;
        for (int y = 0; y < NUM_BOXES; y++) {
            for (int x = 0; x < NUM_BOXES; x++) {
                vector<char> v;
                for (int r = BOX_SIZE * y; r < BOX_SIZE * (y + 1); r++) {
                    for (int c = BOX_SIZE * x; c < BOX_SIZE * (x + 1); c++) {
                        if (board[r][c] == EMPTY) {
                            continue;
                        }
                        v.push_back(board[r][c]);
                    }
                }

                if (!isValid(v)) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
private:
    bool isValid(vector<char>& v) {
        set<char> s = set<char>(v.begin(), v.end());
        if (s.size() != v.size()) {
            return false;
        }        
        
        for (char c: v) {
            // if (c != '.' && (c < '1' || c > '9')) {
            if (c < '1' || c > '9') {
                return false;
            }
        }
        
        return true;
    }
};

int main() {
    Solution soln;
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    cout << soln.isValidSudoku(board) << endl;

    return 0;
}