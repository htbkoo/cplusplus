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
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> positions;

        positions[0] = -1;

        int answer = 0;
        int curr = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                curr--;
            } else if (nums[i] == 1) {
                curr++;
            } else {
                // TODO: throw error here
            }

            if (positions.count(curr) == 0) {
                positions[curr] = i;
            } else {
                answer = max(
                    answer,
                    i - positions[curr]
                );
            }
        }

        return answer;
    }
};