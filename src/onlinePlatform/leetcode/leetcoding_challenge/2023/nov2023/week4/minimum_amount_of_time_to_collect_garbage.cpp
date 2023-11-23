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
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        set<pair<int, int>> visited;

        queue<pair<int, int>> q;
        q.push(pair{0, 0});

        vector<int> answer;

        while (q.size() > 0) {
            auto [y, x] = q.front();
            q.pop();

            if (y >= nums.size() || x >= nums[y].size() || visited.count(pair{y, x}) > 0) {
                continue;
            }
            visited.insert(pair{y, x});

            answer.push_back(nums[y][x]);

            q.push(pair{y + 1, x});
            q.push(pair{y, x + 1});
        }

        return answer;
    }
};