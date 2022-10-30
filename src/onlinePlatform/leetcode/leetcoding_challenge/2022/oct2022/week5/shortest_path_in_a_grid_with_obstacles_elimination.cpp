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

struct State {
    int y;
    int x;
    int remainK;
    int numStep;
    
    State(int y, int x, int remainK, int numStep): y(y), x(x), remainK(remainK), numStep(numStep) {}
};

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        vector<pair<int, int>> DIRECTIONS = {
            pair{-1, 0},
            pair{1, 0},
            pair{0, -1},
            pair{0, 1},
        };
        
        int OBSTACLE = 1;
        int IMPOSSIBLE = -1;
        
        int HEIGHT = grid.size();
        int WIDTH = grid[0].size();
        
        int TARGET_Y = HEIGHT - 1;
        int TARGET_X = WIDTH - 1;
        
        initBestSteps(HEIGHT, WIDTH, k);
        
        queue<State> states = queue<State>({State(START_Y, START_X, k, 0)});
        
        while (states.size() > 0) {
            State state = states.front();
            states.pop();
            
            if (state.y == TARGET_Y && state.x == TARGET_X) {
                return state.numStep;
            }
                        
            for (auto &[dy, dx]: DIRECTIONS) {
                int ny = state.y + dy;
                int nx = state.x + dx;
                int newNumStep = state.numStep + 1;
                int newRemainK = state.remainK;
                bool isWithinBoundary = 0 <= ny && ny < HEIGHT && 0 <= nx && nx < WIDTH;
                if (isWithinBoundary) {
                    bool isBlocked = grid[ny][nx] == OBSTACLE;
                    if (isBlocked) {
                        if (state.remainK == 0) {
                            continue;
                        }
                        newRemainK--;
                    }
                    
                    int prevBestRemainK = bestRemainK[ny][nx];
                    if (newRemainK <= prevBestRemainK) {
                        continue;
                    }
                    bestRemainK[ny][nx] = newRemainK;

                    states.push(State(ny, nx, newRemainK, newNumStep));
                }
            }
        }
        
        return IMPOSSIBLE;
    }
    
private:
    vector<vector<int>> bestRemainK;    
    int START_Y = 0;
    int START_X = 0;

    void initBestSteps(int HEIGHT, int WIDTH, int k) {
        for (int y = 0; y < HEIGHT; y++) {
            bestRemainK.push_back(vector<int>());
            for (int x = 0; x < WIDTH; x++) {
                bestRemainK[y].push_back(-1);
            }
        }
    }  
};

int main() {
    Solution soln;
    vector<vector<int>> grid = {{0,0,0},{1,1,0},{0,0,0},{0,1,1},{0,0,0}};
    int k = 1;
    cout << soln.shortestPath(grid, k) << endl;
}