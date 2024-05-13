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
    int matrixScore(vector<vector<int>>& grid) {
        int HEIGHT = grid.size();
        int WIDTH = grid[0].size();

        for (int y = 0; y < HEIGHT; ++y) {
            if (grid[y][0] == 0) {
                for (int x = 0; x < WIDTH; ++x) {
                    grid[y][x] = 1 - grid[y][x];
                }
            }
        }

        int answer = HEIGHT * (int) pow(2, WIDTH - 1);
        for (int x = 1; x < WIDTH; ++x) {
            int count = 0;
            for (int y = 0; y < HEIGHT; ++y) {
                count += grid[y][x];
            }

            count = max(count, HEIGHT - count);

            answer += count * (int) pow(2, WIDTH - 1 - x);
        }

        return answer;
    }
};

class WASolution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int HEIGHT = grid.size();
        int WIDTH = grid[0].size();

        int answer = 0;

        for (int x = 0; x < WIDTH; ++x) {
            int count = 0;
            for (int y = 0; y < HEIGHT; ++y) {
                count += grid[y][x];
            }

            count = max(count, HEIGHT - count);

            answer += count * (int) pow(2, WIDTH - 1 - x);
        }

        return answer;
    }
};
