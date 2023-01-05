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
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) {
            return 0;
        }
        
        // this will throw `applying non-zero offset 4 to null pointer` runtime error
        // sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) { return a[1] <= b[1]; });
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });
        
        int answer = 1;
        int currEnd = points[0][1];
        for (int i = 1; i < points.size(); i++) {
            int start = points[i][0];
            if (start > currEnd) {
                answer++;
                int end = points[i][1];
                currEnd = end;
            }
        }
        
        return answer;
    }
};
