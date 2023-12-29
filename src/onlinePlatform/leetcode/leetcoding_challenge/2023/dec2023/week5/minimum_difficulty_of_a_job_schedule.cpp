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
const int INVALID = 1000 * 10 + 1;

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if (jobDifficulty.size() == 0) {
            // TODO: confirm this
            return 0;
        }

        if (jobDifficulty.size() < d) {
            return -1;
        }

        memo = vector<vector<vector<int>>>();

        int maxDifficulty = *max_element(begin(jobDifficulty), end(jobDifficulty));

        for (int i = 0; i <= jobDifficulty.size(); ++i) {
            memo.push_back(vector<vector<int>>());
            for (int j = 0; j <= maxDifficulty; ++j) {
                memo[i].push_back(vector<int>(d + 1, UNINITIALIZED));
            }
        }

        // return findMin(jobDifficulty, 1, jobDifficulty[0], d - 1);
        return findMin(jobDifficulty, 0, 0, d);
    }

private:
    vector<vector<vector<int>>> memo;

    int findMin(vector<int>& jobDifficulty, int i, int prevMax, int d) {
        if (i >= jobDifficulty.size() && d == 0) {
            return prevMax;
        }

        if (i >= jobDifficulty.size() || d < 0) {
            return INVALID;
        }

        if (memo[i][prevMax][d] == UNINITIALIZED) {
            int sameDay = findMin(jobDifficulty, i + 1, max(prevMax, jobDifficulty[i]), d);
            int newDay = prevMax + findMin(jobDifficulty, i + 1, jobDifficulty[i], d - 1);

            memo[i][prevMax][d] = min(sameDay, newDay);
        }

        return memo[i][prevMax][d];
    }
};

class WASolution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if (jobDifficulty.size() == 0) {
            // TODO: confirm this
            return 0;
        }

        if (jobDifficulty.size() < d) {
            return -1;
        }

        memo = vector<vector<vector<int>>>();

        int maxDifficulty = *max_element(begin(jobDifficulty), end(jobDifficulty));

        for (int i = 0; i <= jobDifficulty.size(); ++i) {
            memo.push_back(vector<vector<int>>());
            for (int j = 0; j <= maxDifficulty; ++j) {
                memo[i].push_back(vector<int>(d + 1, UNINITIALIZED));
            }
        }

        // return findMin(jobDifficulty, 1, jobDifficulty[0], d - 1);
        return findMin(jobDifficulty, 0, 0, d);
    }

private:
    vector<vector<vector<int>>> memo;

    int findMin(vector<int>& jobDifficulty, int i, int prevMax, int d) {
        if (i >= jobDifficulty.size() && d == 0) {
            return prevMax;
        }

        if (i >= jobDifficulty.size() || d == 0) {
            return INVALID;
        }

        if (memo[i][prevMax][d] == UNINITIALIZED) {
            int sameDay = findMin(jobDifficulty, i + 1, max(prevMax, jobDifficulty[i]), d);
            int newDay = prevMax + findMin(jobDifficulty, i + 1, jobDifficulty[i], d - 1);

            memo[i][prevMax][d] = min(sameDay, newDay);
        }

        return memo[i][prevMax][d];
    }
};