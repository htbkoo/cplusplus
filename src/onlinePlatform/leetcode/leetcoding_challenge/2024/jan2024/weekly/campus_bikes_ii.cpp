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
const int UNINITIALIZED = -1;

class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        memo = vector<vector<int>>();
        for (int w = 0; w < workers.size(); ++w) {
            memo.push_back(vector<int>((int) pow(2, bikes.size()), UNINITIALIZED));
        }

        return findMin(workers, bikes, 0, 0);
    }

private:
    vector<vector<int>> memo;

    int findMin(vector<vector<int>>& workers, vector<vector<int>>& bikes, int w, int bikesBitmask) {
        if (w >= workers.size()) {
            return 0;
        }

        if (memo[w][bikesBitmask] == UNINITIALIZED) {
            memo[w][bikesBitmask] = numeric_limits<int>::max();
            for (int b = 0; b < bikes.size(); ++b) {
                if (isUsed(b, bikesBitmask)) {
                    continue;
                }
                memo[w][bikesBitmask] = min(
                    memo[w][bikesBitmask],
                    getManhattanDistance(workers, bikes, w, b) + findMin(workers, bikes, w + 1, withUse(b, bikesBitmask))
                );
            }
        }

        return memo[w][bikesBitmask];
    }

    bool isUsed(int b, int bikesBitmask) {
        int flag = pow(2, b);
        return (flag & bikesBitmask) > 0;
    }

    int withUse(int b, int bikesBitmask) {
        int flag = pow(2, b);
        return flag | bikesBitmask;
    }

    int getManhattanDistance(vector<vector<int>>& workers, vector<vector<int>>& bikes, int w, int b) {
        int wx = workers[w][0], wy = workers[w][1];
        int bx = bikes[b][0], by = bikes[b][1];

        return abs(wx - bx) + abs(wy - by);
    }
};

class WASolution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        memo = vector<vector<int>>();
        for (int w = 0; w < workers.size(); ++w) {
            memo.push_back(vector<int>((int) pow(2, bikes.size()), UNINITIALIZED));
        }

        return findMin(workers, bikes, 0, 0);
    }

private:
    vector<vector<int>> memo;

    int findMin(vector<vector<int>>& workers, vector<vector<int>>& bikes, int w, int bikesBitmask) {
        if (w >= workers.size()) {
            return 0;
        }


        if (memo[w][bikesBitmask] == UNINITIALIZED) {
            memo[w][bikesBitmask] = numeric_limits<int>::max();
            for (int b = 0; b < bikes.size(); ++b) {
                if (isUsed(b, bikesBitmask)) {
                    continue;
                }
                memo[w][bikesBitmask] = min(
                    memo[w][bikesBitmask],
                    getManhattanDistance(workers, bikes, w, b) + findMin(workers, bikes, w + 1, withUse(b, bikesBitmask))
                );
            }
        }

        return memo[w][bikesBitmask];
    }

    bool isUsed(int b, int bikesBitmask) {
        return (((int) pow(2, b)) & bikesBitmask) > 0;
    }

    bool withUse(int b, int bikesBitmask) {
        return ((int) pow(2, b)) | bikesBitmask;
    }

    int getManhattanDistance(vector<vector<int>>& workers, vector<vector<int>>& bikes, int w, int b) {
        int wx = workers[w][0], wy = workers[w][1];
        int bx = bikes[b][0], by = bikes[b][1];

        return abs(wx - bx) + abs(wy - by);
    }
};
int main() {
    Solution soln;
    vector<vector<int>> workers = {{0,0},{1,1},{2,0}}, bikes = {{1,0},{2,2},{2,1}};

    cout << soln.assignBikes(workers, bikes) << endl;

    return 0;
}