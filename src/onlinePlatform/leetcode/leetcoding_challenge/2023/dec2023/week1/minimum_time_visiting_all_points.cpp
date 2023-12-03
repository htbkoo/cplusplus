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
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int answer = 0;
        for (int i = 1; i < points.size(); ++i) {
            answer += getDist(points[i - 1], points[i]);
        }
        return answer;
    }

private:
    int getDist(vector<int> pointFrom, vector<int> pointTo) {
        int fx = pointFrom[0], fy = pointFrom[1];
        int tx = pointTo[0], ty = pointTo[1];

        return max(
            abs(fx - tx),
            abs(fy - ty)
        );
    }
};
