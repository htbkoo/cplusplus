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
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> answer;
        for (int i = 0; i < n - 2; ++i) {
            answer.push_back(vector<int>(n - 2, numeric_limits<int>::min()));
        }

        for (int y = 1; y < n - 1; ++y) {
            for (int x = 1; x < n - 1; ++x) {
                for (int dy = -1; dy <= 1; ++dy) {
                    for (int dx = -1; dx <= 1; ++dx) {
                        answer[y - 1][x - 1] = max(answer[y - 1][x - 1], grid[y + dy][x + dx]);
                    }
                }
            }
        }

        return answer;
    }
};
