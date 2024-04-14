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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int HEIGHT = matrix.size();
        int WIDTH = matrix[0].size();

        vector<vector<int>> prefixes;
        for (int y = 0; y < HEIGHT; ++y) {
            prefixes.push_back(vector<int>(1, matrix[y][0] - '0'));
            for (int x = 1; x < WIDTH; ++x) {
                if (matrix[y][x] == '0') {
                    prefixes[y].push_back(0);
                } else {
                    prefixes[y].push_back(prefixes[y].back() + 1);
                }
            }
        }

        int answer = 0;
        for (int y = 0; y < HEIGHT; ++y) {
            for (int x = 0; x < WIDTH; ++x) {
                int currWidth = prefixes[y][x];
                for (int y2 = y; y2 < HEIGHT; ++y2) {
                    currWidth = min(currWidth, prefixes[y2][x]);
                    int currHeight = y2 - y + 1;
                    answer = max(answer, currWidth * currHeight);
                }
            }
        }

        return answer;
    }
};
