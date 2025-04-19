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
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(begin(nums), end(nums));
        
        long long answer = 0;
        for (int i = 0; i < nums.size(); ++i) {
            auto num = nums[i];
            
            int left = max(i + 1, (int) distance(begin(nums), lower_bound(begin(nums), end(nums), lower - num)));
            int right = distance(begin(nums),upper_bound(begin(nums), end(nums), upper - num));
            
            answer += max(0, right - left);
        }
        
        return answer;
    }
};

int main() {
    Solution soln;
    vector nums{0,0,0,0,0,0};
    cout << soln.countFairPairs(nums, 0 , 0) << endl;
    return 0;
}