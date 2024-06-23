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
    int longestSubarray(vector<int>& nums, int limit) {
        map<int, int> bst;
        
        int answer = 0;
        int left = 0;
        for (int i = 0; i < nums.size(); ++i) {
            bst[nums[i]]++;
            
            while (bst.size() > 0) {
                int minNum = begin(bst)->first;
                int maxNum = prev(end(bst))->first;
                if (maxNum - minNum <= limit) {
                    break;
                }
                int leftNum = nums[left];
                bst[leftNum]--;
                if (bst[leftNum] == 0) {
                    bst.erase(leftNum);
                }
                left++;
            }
            
            answer = max(answer, i - left + 1);
        }
        
        return answer;
    }
};

int main() {
    Solution soln;

    vector<int>nums{8,2,4,7};
    int limit = 4;

    cout << soln.longestSubarray(nums, limit) << endl;

    return 0;
}