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
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int THIEF = 1;

        int HEIGHT = grid.size();
        int WIDTH = grid[0].size();

        vector<vector<int>> dists(HEIGHT, vector<int>(WIDTH, numeric_limits<int>::max() / 2));

        deque<pair<int, int>> q;
        for (int y = 0; y < HEIGHT; ++y) {
            for (int x = 0; x < WIDTH; ++x) {
                if (grid[y][x] == THIEF) {
                    dists[y][x] = 0;
                    q.push_back(pair{y, x});
                }
            }
        }

        vector<pair<int, int>> DIRECTIONS{
            pair{-1, 0},
            pair{1, 0},
            pair{0, -1},
            pair{0, 1}
        };

        while (q.size() > 0) {
            auto [y, x] = q.front();
            q.pop_front();

            for (auto &[dy, dx]: DIRECTIONS) {
                int ny = y + dy;
                int nx = x + dx;

                bool isWithinBoundary = 0 <= ny && ny < HEIGHT && 0 <= nx && nx < WIDTH;

                if (!isWithinBoundary) {
                    continue;
                }

                if (dists[ny][nx] <= 1 + dists[y][x]) {
                    continue;
                }

                dists[ny][nx] = 1 + dists[y][x];

                q.push_back(pair{ny, nx});
            }
        }

        int START_Y = 0;
        int START_X = 0;
        int END_Y = HEIGHT - 1;
        int END_X = WIDTH - 1;

        priority_queue<tuple<int, int, int>> pq;
        pq.push(tuple{dists[START_Y][START_X], START_Y, START_X});

        set<pair<int, int>> visited;

        while (pq.size() > 0) {
            auto [d, y, x] = pq.top();
            pq.pop();

            if (y == END_Y && x == END_X) {
                return d;
            }

            if (visited.count(pair{y, x}) > 0) {
                continue;
            }
            visited.insert(pair{y, x});

            for (auto &[dy, dx]: DIRECTIONS) {
                int ny = y + dy;
                int nx = x + dx;

                bool isWithinBoundary = 0 <= ny && ny < HEIGHT && 0 <= nx && nx < WIDTH;

                if (!isWithinBoundary) {
                    continue;
                }

                int nd = min(d, dists[ny][nx]);

                pq.push(tuple{nd, ny, nx});
            }
        }

        return -1;
    }
};
