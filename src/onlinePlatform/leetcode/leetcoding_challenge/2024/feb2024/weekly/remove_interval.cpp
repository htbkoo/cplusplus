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
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> answer;

        for (auto &interval: intervals) {
            int start = interval[0], end = interval[1];

            int leftStart = start;
            int leftEnd = min(end, toBeRemoved[0]);

            if (leftEnd > leftStart) {
                answer.push_back({leftStart, leftEnd});
            }

            int rightStart = max(start, toBeRemoved[1]);
            int rightEnd = end;
            if (rightEnd > rightStart && (rightStart != leftStart || rightEnd != rightStart)) {
                answer.push_back({rightStart, rightEnd});
            }
        }

        return answer;
    }
};