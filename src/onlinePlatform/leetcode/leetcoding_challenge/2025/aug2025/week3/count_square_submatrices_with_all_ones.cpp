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
    int countSquares(vector<vector<int>>& matrix) {
        auto HEIGHT = matrix.size();
        auto WIDTH = matrix[0].size();

        int answer = 0;

        vector<int> curr(WIDTH, 0);
        for (auto x = 0; x < WIDTH; ++x) {
            if (matrix[0][x] == 1) {
                curr[x] = 1;
                answer++;
            }
        }

        for (auto y = 1; y < HEIGHT; ++y) {
            vector<int> prev = curr;
            curr = vector<int>(WIDTH, 0);
            if (matrix[y][0] == 1) {
                curr[0] = 1;
                answer++;
            }

            for (auto x = 1; x < WIDTH; ++x) {
                if (matrix[y][x] == 1) {
                    curr[x] = 1 + min(min(prev[x], prev[x - 1]), curr[x - 1]);
                    answer += curr[x];
                }
            }
        }

        return answer;
    }
};