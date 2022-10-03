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
    int minCost(string colors, vector<int>& neededTime) {
        long answer = 0;
        int left = 0;

        for (int right = 0; right <= colors.size(); right++) {
            bool shouldRemove = right == colors.size() || colors[right] != colors[left];
            if (shouldRemove) {
                if (right > (left + 1)) {
                    int maxTime = neededTime[left];
                    int totalTime = 0;
                    for (int i = left; i < right; i++) {
                        auto time = neededTime[i];
                        totalTime += time;
                        maxTime = max(maxTime, time);
                    }
                    answer += (totalTime - maxTime);
                }
                left = right;                
            }
            if (right == colors.size()) {
                break;                
            }       
        }

        return answer;
    }
};

int main() {
    Solution soln;

    vector<int> neededTime = {1,2,3,4,5};

    soln.minCost(
        "abaac",
        neededTime
    );

    return 0;
}