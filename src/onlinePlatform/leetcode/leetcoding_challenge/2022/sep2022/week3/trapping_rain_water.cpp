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
    int trap(vector<int>& height) {
        if (height.size() == 0) {
            return 0;
        }
        
        vector<int> leftToRight = vector<int>(height.size());
        leftToRight[0] = height[0];
        for (int i = 1; i < height.size(); i++) {
            leftToRight[i] = max(leftToRight[i - 1], height[i]);
        }
        
        vector<int> rightToLeft = vector<int>(height.size());
        rightToLeft[height.size() - 1] = height[height.size() - 1];
        for (int i = height.size() - 2; i >= 0; i--) {
            rightToLeft[i] = max(rightToLeft[i + 1], height[i]);
        }
        
        int answer = 0;
        for (int i = 0; i < height.size(); i++) {
            answer += min(leftToRight[i], rightToLeft[i]) - height[i];
        }
        
        return answer;
    }
};