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
    int minCost(vector<vector<int>>& costs) {
        int r = 0, g = 0, b = 0;

        for (int i = 0; i < costs.size(); ++i) {
            int pr = r, pg = g, pb = b;

            r = min(pg, pb) + costs[i][0];
            g = min(pr, pb) + costs[i][1];
            b = min(pg, pr) + costs[i][2];

        }

        return min(r, min(g, b));
    }
};

int main() {
    Solution soln;
    vector<vector<int>> costs = {{17,2,17},{16,16,5},{14,3,19}};

    cout << soln.minCost(costs) << endl;

    return 0;
}