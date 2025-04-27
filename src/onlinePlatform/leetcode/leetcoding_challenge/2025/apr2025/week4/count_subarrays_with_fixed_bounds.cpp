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
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        vector<int> nextInvalidIndices(nums.size());
        int nextInvalidIdx = nums.size();
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] < minK || nums[i] > maxK) {
                nextInvalidIdx = i;
            }
            nextInvalidIndices[i] = nextInvalidIdx;
        }
        
        long long answer = 0;
        int left = 0;
        multiset<int> bst;        
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] < minK || nums[right] > maxK) {                
                bst = multiset<int>();
                right++;
                left = right;
                continue;
            }
            
            while (bst.size() > 0 && *begin(bst) == minK && *end(bst) == maxK) {
                int count = nextInvalidIndices[right] - right;
                answer += count;
                bst.erase(nums[left]);
                left++;
            }
                
            right++;
        }
        
        while (bst.size() > 0 && *begin(bst) == minK && *end(bst) == maxK) {
            answer++;
            bst.erase(nums[left]);
            left++;
        }
        
        return answer;
    }
};

int main() {
    Solution soln;

    cout << "helloworld" << endl;

    // vector<int> nums{1,3,5,2,7,5};
    // cout << soln.countSubarrays(nums, 1, 5) << endl;

    return 0;
}