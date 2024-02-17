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
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> usedBricks;

        for (int i = 1; i < heights.size(); ++i) {
            if (heights[i] > heights[i - 1]) {
                int needBricks = heights[i] - heights[i - 1];

                while (ladders > 0 && usedBricks.size() > 0 && bricks < needBricks) {
                    int releasedBricks = usedBricks.top();
                    usedBricks.pop();

                    ladders -= 1;
                    bricks += releasedBricks;
                }

                if (bricks < needBricks && ladders == 0) {
                    return i - 1;
                } else if (bricks >= needBricks) {
                    bricks -= needBricks;
                    usedBricks.push(needBricks);
                } else {
                    ladders -= 1;
                }
            }
        }

        return heights.size() - 1;
    }
};

int main() {
    Solution soln;
    vector<int> heights{4,12,2,7,3,18,20,3,19};
    int bricks = 10, ladders = 2;

    cout << soln.furthestBuilding(heights, bricks, ladders) << endl;

    return 0;
}