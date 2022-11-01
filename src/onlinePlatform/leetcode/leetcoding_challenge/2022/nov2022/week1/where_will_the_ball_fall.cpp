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
    vector<int> findBall(vector<vector<int>>& grid) {
        int BOARD_RIGHT = 1;
        int BOARD_LEFT = -1;
        int STUCK = -1;
        
        int HEIGHT = grid.size();
        int WIDTH = grid[0].size();
        
        vector<int> answer = vector<int>(WIDTH);
        for (int i = 0; i < WIDTH; i++) {
            answer[i] = i;
            for (vector<int> &row: grid) {
                int pos = answer[i];
                if (row[pos] == BOARD_RIGHT) {
                    bool canGoRight = pos < WIDTH - 1 && row[pos + 1] == BOARD_RIGHT;
                    if (canGoRight) {
                        answer[i] += 1;
                    } else {
                        answer[i] = STUCK;
                        break;
                    }                    
                } else if (row[pos] == BOARD_LEFT) {
                    bool canGoLeft = pos >0 && row[pos - 1] == BOARD_LEFT;
                    if (canGoLeft) {
                        answer[i] -= 1;
                    } else {
                        answer[i] = STUCK;
                        break;
                    }
                } else {
                    throw invalid_argument("invalid grid");
                }
                
                if (answer[i] < 0 || answer[i] >= WIDTH) {
                    answer[i] = STUCK;
                    break;
                }
            }
        }
        
        return answer;
    }
};