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

int START_Y = 0;
int START_X = 0;

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
        
        initBestSteps(k);
        
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
                    
                    pair<int, int> newCoords = pair{ny, nx};
                    int prevBestStep = getBestStep(newRemainK, newCoords);
                    if (newNumStep >= prevBestStep) {
                        continue;
                    }
                    
                    setBestStep(newRemainK, newCoords, newNumStep);
                    states.push(State(ny, nx, newRemainK, newNumStep));
                }
            }
        }
        
        return IMPOSSIBLE;
    }
    
private:
    unordered_map<int, map<pair<int, int>, int>> bestSteps;
    
    void initBestSteps(int k) {
        for (int remainK = 0; remainK <= k; remainK++) {
            bestSteps[remainK] = {};
            bestSteps[remainK][pair{START_Y, START_X}] = 0;
        }
    }
    
    int getBestStep(int remainK, pair<int, int> coords) {
        return numeric_limits<int>::max();

        if (bestSteps.count(remainK) == 0) {
            return numeric_limits<int>::max();
        }
            
        if (bestSteps[remainK].count(coords) == 0) {
            return numeric_limits<int>::max();
        }
        
        return bestSteps[remainK][coords];
    }
    
    void setBestStep(int remainK, pair<int, int> coords, int bestStep) {
        if (bestSteps.count(remainK) == 0) {
            bestSteps[remainK] = {};
        }
        
        bestSteps[remainK][coords] = bestStep;
    }
};

int main() {
    Solution soln;
    vector<vector<int>> grid = {{0,0,0},{1,1,0},{0,0,0},{0,1,1},{0,0,0}};
    int k = 1;
    cout << soln.shortestPath(grid, k) << endl;
}