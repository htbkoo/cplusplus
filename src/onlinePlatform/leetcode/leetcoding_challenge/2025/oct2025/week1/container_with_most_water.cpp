// leetcode.com/classic/problems/container-with-most-water/?envType=daily-question&envId=2025-10-04

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
    int maxArea(vector<int>& height) {
        int lo = 0;
        int hi = height.size() - 1;

        int answer = 0;
        while (lo < hi) {
            answer = max(answer, min(height[lo], height[hi]) * (hi - lo));
            if (height[lo] < height[hi]) {
                lo++;
            } else {
                hi--;
            }
        }

        return answer;
    }
};
