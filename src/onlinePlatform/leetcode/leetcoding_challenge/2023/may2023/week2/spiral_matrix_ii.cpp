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
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> answer;
        for (int i = 0; i < n; ++i) {
            answer.push_back(vector<int>(n, 0));
        }
        
        vector<pair<int, int>> DIRECTIONS = {pair{0, 1}, pair{1, 0}, pair{0, -1}, pair{-1, 0}};
        int dirIdx = 0;
        
        int y = 0;
        int x = 0;
        
        for (int i = 1; i <= n * n; ++i) {
            answer[y][x] = i;
            
            auto& [dy, dx] = DIRECTIONS[dirIdx];
                        
            int ny = y + dy, nx = x + dx;
            bool isWithinBoundary = 0 <= ny && ny < n && 0 <= nx && nx < n;
            bool shouldTurn = !isWithinBoundary || answer[ny][nx] != 0;
            if (shouldTurn) {
                dirIdx = (dirIdx + 1) % DIRECTIONS.size();
                auto& [dy, dx] = DIRECTIONS[dirIdx];
                ny = y + dy;
                nx = x + dx;
            } 

            y = ny;
            x = nx;
        }
        
        return answer;
    }
};