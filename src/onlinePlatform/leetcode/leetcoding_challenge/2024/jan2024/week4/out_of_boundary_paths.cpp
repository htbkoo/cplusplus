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
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int MOD = pow(10, 9) + 7;

        vector<vector<int>> counts;
        for (int y = 0; y < m; y++) {
            counts.push_back(vector<int>(n, 0));
        }
        counts[startRow][startColumn] = 1;

        int answer = 0;

        vector<tuple<int, int>> DIRECTIONS = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };

        for (int k = 0; k < maxMove; k++) {
            vector<vector<int>> prev = counts;
            counts = vector<vector<int>>();
            for (int y = 0; y < m; y++) {
                counts.push_back(vector<int>(n, 0));
            }

            for (int y = 0; y < m; y++) {
                for (int x = 0; x < n; x++) {
                    for (auto& [dy, dx]: DIRECTIONS) {
                        int ny = y + dy;
                        int nx = x + dx;

                        bool isWithinBoundary = 0 <= ny && ny < m && 0 <= nx && nx < n;
                        if (isWithinBoundary) {
                            counts[ny][nx] = (counts[ny][nx] + prev[y][x]) % MOD;
                        } else {
                            answer = (answer + prev[y][x]) % MOD;
                        }
                    }
                }
            }
        }

        return answer;
    }
};

int main() {
    Solution soln;

    cout << soln.findPaths(2,2,2,0,0) << endl;

    return 0;
}