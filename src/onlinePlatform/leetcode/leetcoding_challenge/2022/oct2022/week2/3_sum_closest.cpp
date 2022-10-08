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
    int threeSumClosest(vector<int>& nums, int target) {
        vector<int> sortedNums = vector<int>(nums);
        sort(sortedNums.begin(), sortedNums.end());
        
        int answer = numeric_limits<int>::max();
        for (int i = 0; i < sortedNums.size(); i++) {
            for (int j = i + 1; j < sortedNums.size() - 1; j++) {
                int remainSum = target - sortedNums[i] - sortedNums[j];
                auto it = lower_bound(sortedNums.begin() + j + 1, sortedNums.end(), remainSum);
                if (it == sortedNums.end()) {
                    it--;
                }
                
                long totalSum = sortedNums[i] + sortedNums[j] + *it;
                if (abs(totalSum - target) < abs((long)answer - target)) {
                    answer = totalSum;
                }
            }   
        }
        
        return answer;
    }
};

int main() {
    Solution soln;
    // vector<int> nums = {-1,2,1,-4};
    // cout << soln.threeSumClosest(nums, 1) << endl;
    vector<int> nums = {1, 1, 1, 1};
    cout << soln.threeSumClosest(nums, -100) << endl;

    return 0;
}