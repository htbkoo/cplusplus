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
    int numWays(int n, int k) {
        if (n == 0 || k == 0) {
            // TODO: confirm this, and what if n < 0 or k < 0?
            return 0;
        }

        if (n == 1) {
            return k;
        }

        if (n == 2) {
            return k * k;
        }

        if (n == 3) {
            return k * k * k - k;
        }

        memo = vector<vector<vector<int>>>();
        for (int i = 0; i < n; ++i) {
            memo.push_back(vector<vector<int>>());
            for (int j = 0; j <= k; ++j) {
                memo.back().push_back(vector<int>(k + 1, UNINITIALIZED));
            }
        }

        int NO_COLOR = k;
        return count(n, k, 0, NO_COLOR, NO_COLOR);
    }

private:
    vector<vector<vector<int>>> memo;

    int count(int n, int k, int i, int prevprev, int prev) {
        if (i >= n) {
            return 1;
        }

        if (memo[i][prevprev][prev] == UNINITIALIZED) {
            memo[i][prevprev][prev] = 0;
            for (int j = 0; j < k; ++j) {
                bool noThreeConsecutive = j != prevprev || j != prev;
                if (noThreeConsecutive) {
                    memo[i][prevprev][prev] += count(n, k, i + 1, prev, j);
                }
            }
        }

        return memo[i][prevprev][prev];
    }

    int sum(vector<int>& v) {
        int total = 0;
        for (auto item: v) {
            total += item;
        }
        return total;
    }
};

class WIPSolution {
public:
    int numWays(int n, int k) {
        if (n == 0 || k == 0) {
            // TODO: confirm this, and what if n < 0 or k < 0?
            return 0;
        }

        vector<vector<int>> prev;
        for (int j = 0; j <= k; ++j) {
            prev.push_back(vector<int>(k + 1, 0));
        }
        vector<int> curr(k + 1, 0);

        for (int i = 0; i < n; ++i) {
            vector<vector<int>> curr;
            for (int j = 0; j <= k; ++j) {
                curr.push_back(vector<int>(k + 1, 0));
            }

            for (int p = 0; p < k; ++p) {
                for (int pp = 0; pp < k; ++pp) {
                    // curr[p]
                }
            }
            prev = curr;
        }

        int total = 0;
        for (int p = 0; p < k; ++p) {
            for (int pp = 0; pp < k; ++pp) {
                total += prev[p][pp];
            }
        }

        return total;
    }
};

class MLESolution {
public:
    int numWays(int n, int k) {
        if (n == 0 || k == 0) {
            // TODO: confirm this, and what if n < 0 or k < 0?
            return 0;
        }

        memo = vector<vector<vector<int>>>();
        for (int i = 0; i < n; ++i) {
            memo.push_back(vector<vector<int>>());
            for (int j = 0; j <= k; ++j) {
                memo.back().push_back(vector<int>(k + 1, UNINITIALIZED));
            }
        }

        int NO_COLOR = k;
        return count(n, k, 0, NO_COLOR, NO_COLOR);
    }

private:
    vector<vector<vector<int>>> memo;

    int count(int n, int k, int i, int prevprev, int prev) {
        if (i >= n) {
            return 1;
        }

        if (memo[i][prevprev][prev] == UNINITIALIZED) {
            memo[i][prevprev][prev] = 0;
            for (int j = 0; j < k; ++j) {
                bool noThreeConsecutive = j != prevprev || j != prev;
                if (noThreeConsecutive) {
                    memo[i][prevprev][prev] += count(n, k, i + 1, prev, j);
                }
            }
        }

        return memo[i][prevprev][prev];
    }

    int sum(vector<int>& v) {
        int total = 0;
        for (auto item: v) {
            total += item;
        }
        return total;
    }
};

class WASolution {
public:
    int numWays(int n, int k) {
        if (n == 0 || k == 0) {
            // TODO: confirm this, and what if n < 0 or k < 0?
            return 0;
        }

        vector<int> colors(k, 1);

        for (int i = 2; i <= n; ++i) {
            // TODO: beware of overflow
            vector<int> prev = colors;
            int total = sum(colors);
            colors = vector<int>(k, 0);

            for (int j = 0; j < k; ++j) {
                colors[j] = total - prev[j];
            }
        }

        return sum(colors);
    }

    int sum(vector<int>& v) {
        int total = 0;
        for (auto item: v) {
            total += item;
        }
        return total;
    }
};
int main() {
    Solution soln;

    cout << soln.numWays(3,2) << endl;

    return 0;
}