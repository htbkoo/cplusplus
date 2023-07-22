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
    double knightProbability(int n, int k, int row, int column) {
        vector<pair<int, int>> DIRECTIONS = {
            pair{-1, -2},
            pair{-2, -1},
            pair{-2, 1},
            pair{-1, 2},
            pair{1, -2},
            pair{2, -1},
            pair{2, 1},
            pair{1, 2}
        };
        
        vector<vector<double>> probabilities;
        for (int i = 0; i < n; i++) {
            probabilities.push_back(vector<double>(n, 0));
        }
        probabilities[row][column] = 1;
        
        for (int i = 0; i < k; i++) {
            auto prevProbabilities = probabilities;
            probabilities = vector<vector<double>>();
            for (int i = 0; i < n; i++) {
                probabilities.push_back(vector<double>(n, 0));
            }

            for (int y = 0; y < n; ++y) {
                for (int x = 0; x < n; ++x) {
                    for (auto& [dy, dx]: DIRECTIONS) {
                        int py = y + dy;
                        int px = x + dx;
                        bool isWithinBoundary = 0 <= py && py < n && 0 <= px && px < n;
                        if (isWithinBoundary) {
                            probabilities[y][x] += prevProbabilities[py][px] / DIRECTIONS.size();
                        }
                    }
                }
            }
        }
        
        double answer = 0;
        for (auto& row: probabilities) {
            for (auto p: row) {
                answer += p;
            }
        }
        return answer;
    }
};