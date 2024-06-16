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
    int minPatches(vector<int>& nums, int n) {
        int idx = 0;
        long curr = 1;

        int answer = 0;
        while (curr <= n) {
            if (idx < nums.size() && nums[idx] <= curr) {
                curr += nums[idx];
                idx++;
            } else {
                curr *= 2;
                answer++;
            }
        }

        return answer;
    }
};
