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

const int UNINITIALIZED = numeric_limits<int>::max();

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int height = mat.size();
        int width = mat[0].size();        
        vector<pair<int, int>> DIRECTIONS = {
            pair{-1, 0},
            pair{1, 0},
            pair{0, -1},
            pair{0, 1}
        };

        vector<vector<int>> answer;
        for (int y = 0; y < height; ++y) {
            answer.push_back(vector<int>(width, UNINITIALIZED));
        }
        
        queue<pair<int, int>> q;
        
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                if (mat[y][x] == 0) {
                    answer[y][x] = 0;
                    q.push(pair{y, x});
                }
            }
        }
        
        while (q.size() > 0) {
            auto [y, x] = q.front();
            q.pop();

            for (auto& [dy, dx]: DIRECTIONS) {
                int ny = y + dy;
                int nx = x + dx;  

                bool isWithinBoundary = 0 <= ny && ny < height && 0 <= nx && nx < width;
                if (isWithinBoundary) {
                    if (answer[y][x] + 1 < answer[ny][nx]) {
                        answer[ny][nx] = answer[y][x] + 1;
                        q.push(pair{ny, nx});
                    }
                }
            }            
        }

        return answer;
    }
};

class WASolution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int height = mat.size();
        int width = mat[0].size();        
        
        vector<vector<int>> answer;
        for (int y = 0; y < height; ++y) {
            answer.push_back(vector<int>(width, UNINITIALIZED));
        }
        
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                answer[y][x] = findDist(mat, y, x, answer);
            }
        }
        
        return answer;
    }
    
private:
    const vector<pair<int, int>> DIRECTIONS = {
        pair{-1, 0},
        pair{1, 0},
        pair{0, -1},
        pair{0, 1}
    };
    
    int findDist(vector<vector<int>>& mat, int y, int x, vector<vector<int>>& answer) {
        if (answer[y][x] == UNINITIALIZED) {
            if (mat[y][x] == 0) {
                answer[y][x] = 0;
            } else {
                answer[y][x] = numeric_limits<int>::max() / 2;
                for (auto& [dy, dx]: DIRECTIONS) {
                    int ny = y + dy;
                    int nx = x + dx;
                    int height = mat.size();
                    int width = mat[0].size();        
                    
                    bool isWithinBoundary = 0 <= ny && ny < height && 0 <= nx && nx < width;
                    if (isWithinBoundary) {
                        answer[y][x] = min(
                            answer[y][x],
                            1 + findDist(mat, ny, nx, answer)
                        );
                    }
                }
            }
        }
        
        return answer[y][x];
    }
};