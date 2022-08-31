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
    vector<pair<int, int>> DIRECTIONS = {
        pair{-1, 0},
        pair{1, 0},
        pair{0, -1},
        pair{0, 1},
    };

    vector<vector<bool>> new2dVector(int height, int width) {
        vector<vector<bool>> v;
        for (int y = 0; y < height; y++){
            v.push_back(vector<bool>(width));
        }
        return v;
    }

    void bfs(vector<vector<int>>& heights, vector<vector<bool>>& reach, queue<pair<int, int>> q) {
        int height = heights.size();
        int width = heights[0].size();

        
        vector<vector<bool>> visited = new2dVector(height, width);

        while (q.size() > 0) {
            pair<int, int> coors = q.front();
            q.pop();
            int y = coors.first;
            int x = coors.second;
            if (visited[y][x]) {
                continue;
            }
            visited[y][x] = true;
            reach[y][x] = true;
            
            for (pair<int, int> direction: DIRECTIONS){
                int dy = direction.first;
                int dx = direction.second;
                int ny = y + dy;
                int nx = x + dx;
                bool isWithinBoundary = 0 <= ny && ny < height && 0 <= nx && nx < width;
                bool canFlow = isWithinBoundary && heights[ny][nx] >= heights[y][x];
                if (canFlow) {
                    q.push(pair{ny, nx});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int height = heights.size();
        int width = heights[0].size();

        queue<pair<int, int>> q;

        q = queue<pair<int, int>>();
        vector<vector<bool>> pacific = new2dVector(height, width);
        for (int x = 0; x < width; x++) {
            pacific[0][x] = true;
            q.push(pair{0, x});
        }
        for (int y = 0; y < height; y++) {
            pacific[y][0] = true;
            q.push(pair{y, 0});
        }
        bfs(heights, pacific, q);
        
        q = queue<pair<int, int>>();
        vector<vector<bool>> atlantic = new2dVector(height, width);
        for (int x = 0; x < width; x++) {
            atlantic[height - 1][x] = true;
            q.push(pair{height - 1, x});
        }
        for (int y = 0; y < height; y++) {
            atlantic[y][width - 1] = true;
            q.push(pair{y, width - 1});
        }
        bfs(heights, atlantic, q);

        vector<vector<int>> answer;
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if (pacific[y][x] && atlantic[y][x]) {
                    answer.push_back({y, x});
                }
            }
        }
        return answer;
    }
};


class WASolution {
public:
    vector<vector<bool>> new2dVector(int height, int width) {
        vector<vector<bool>> v;
        for (int y = 0; y < height; y++){
            v.push_back(vector<bool>(width));
        }
        return v;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int height = heights.size();
        int width = heights[0].size();

        vector<vector<bool>> pacific = new2dVector(height, width);
        for (int x = 0; x < width; x++) {
            pacific[0][x] = true;
        }
        for (int y = 0; y < height; y++) {
            pacific[y][0] = true;
        }
        for (int y = 1; y < height; y++) {
            for (int x = 1; x < width; x++) {
                bool canTouchViaTop = heights[y][x] >= heights[y - 1][x] && pacific[y - 1][x];
                bool canTouchViaLeft = heights[y][x] >= heights[y][x - 1] && pacific[y][x - 1];
                bool canTouchPacific = canTouchViaTop || canTouchViaLeft;
            }
        }
        
        vector<vector<bool>> atlantic = new2dVector(height, width);
        for (int x = 0; x < width; x++) {
            atlantic[height - 1][x] = true;
        }
        for (int y = 0; y < height; y++) {
            atlantic[y][width - 1] = true;
        }
        for (int y = height - 2; y >= 0; y--) {
            for (int x = width - 2; x >= 0; x--) {
                bool canTouchViaBottom = heights[y][x] >= heights[y + 1][x] && atlantic[y + 1][x];
                bool canTouchViaRight = heights[y][x] >= heights[y][x + 1] && atlantic[y][x + 1];
                bool canTouchAtlantic = canTouchViaBottom || canTouchViaRight;
            }
        }

        vector<vector<int>> answer;
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if (pacific[y][x] && atlantic[y][x]) {
                    answer.push_back({y, x});
                }
            }
        }
        return answer;
    }
};

int main() {
    Solution soln;
   
    vector<vector<int>> heights = {{1,2,3},{4,5,6},{7,8,9}};
    auto answer = soln.pacificAtlantic(heights);

    return 0;
}