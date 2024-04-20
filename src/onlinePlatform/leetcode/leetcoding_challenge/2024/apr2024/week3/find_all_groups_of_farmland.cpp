#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <limits>
#include <map>
#include <set>
#include <unordered_map>
#include <iterator>
#include <sstream>
#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text

vector<pair<int, int>> DIRECTIONS{
    pair{-1, 0},
    pair{1, 0},
    pair{0, -1},
    pair{0, 1}
};

int FORESTED_LAND = 0;
int FARMLAND = 1;

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int HEIGHT = land.size();
        int WIDTH = land[0].size();

        vector<vector<int>> answer;

        for (int y = 0; y < HEIGHT; ++y) {
            for (int x = 0; x < WIDTH; ++x) {
                auto coors = getCoordinates(land, y, x);
                if (coors.size() > 0) {
                    answer.push_back(coors);
                }
            }
        }

        return answer;
    }

private:
    vector<int> getCoordinates(vector<vector<int>>& land, int y, int x) {
        int HEIGHT = land.size();
        int WIDTH = land[0].size();

        bool isWithinBoundary = 0 <= y && y < HEIGHT && 0 <= x & x < WIDTH;
        if (!isWithinBoundary) {
            return {};
        }

        if (land[y][x] == FORESTED_LAND) {
            return {};
        }
        land[y][x] = FORESTED_LAND;

        int r1 = y;
        int c1 = x;
        int r2 = y;
        int c2 = x;

        for (auto &[dy, dx]: DIRECTIONS) {
            auto coors = getCoordinates(land, y + dy, x + dx);
            if (coors.size() > 0) {
                r1 = min(r1, coors[0]);
                c1 = min(c1, coors[1]);
                r2 = max(r2, coors[2]);
                c2 = max(c2, coors[3]);
            }
        }

        return {r1, c1, r2, c2};
    }
};
