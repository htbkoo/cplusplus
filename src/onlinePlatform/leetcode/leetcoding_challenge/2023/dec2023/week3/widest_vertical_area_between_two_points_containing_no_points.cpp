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
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int> xs;
        for (auto& point: points){
            int x = point[0];
            xs.insert(x);
        }

        if (xs.size() <= 1) {
            return 0;
        }

        int answer = 0;
        auto curr = next(begin(xs));

        while (curr != end(xs)) {
            int diff = *curr - *prev(curr);
            answer = max(answer, diff);

            curr = next(curr);
        }

        return answer;
    }
};