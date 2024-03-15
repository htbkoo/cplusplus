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
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // sort(begin(intervals), end(intervals), [](vector<int>& a, vector<int>& b) {});

        map<int, int> events;
        for (auto& interval: intervals) {
            int start = interval[0], end = interval[1];
            events[start]++;
            events[end]--;
        }

        int answer = 0;
        int curr = 0;
        for (auto& [_, diff]: events) {
            curr += diff;
            answer = max(answer, curr);
        }

        return answer;
    }
};