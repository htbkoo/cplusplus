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
        int right = 0;
        multiset<int> bst;        
        while (right < nums.size()) {
            cout << "right: " << right << " nextInvalidIndices[right]: " << nextInvalidIndices[right] << endl;
            if (nums[right] < minK || nums[right] > maxK) {       
                cout << "reset" << endl;
                bst = multiset<int>();
                right++;
                left = right;
                continue;
            }
            
            bst.insert(nums[right]);
            
            try {                
                cout << right << " " ;
                cout << *begin(bst) << " _ " ;
                cout << *prev(end(bst)) << " __ ";
                cout << *end(bst) << " ___ " << endl;
            } catch (const std::exception& e) {
                cout << " _e_ " << endl;
            }
            
            while (bst.size() > 0 && *begin(bst) == minK && *prev(end(bst)) == maxK) {
                int count = nextInvalidIndices[right] - right;
                cout << "add count: " << count << " answer:" << answer << endl;
                answer += count;
                bst.erase(nums[left]);

                cout << "now: " << *begin(bst) << " _ " << *prev(end(bst)) << endl;
                left++;
            }
                
            right++;
        }
        
        while (bst.size() > 0 && *begin(bst) == minK && *prev(end(bst)) == maxK) {
            answer++;
            bst.erase(nums[left]);
            left++;
        }
        
        return answer;
    }
};

int main() {
    Solution soln;

    // vector<int> nums{1,3,5,2,7,5};

    // cout << soln.countSubarrays(nums, 1, 5) << endl;
    vector<int> nums{35054,398719,945315,945315,820417,945315,35054,945315,171832,945315,35054,109750,790964,441974,552913};
    cout << soln.countSubarrays(nums, 35054, 945315) << endl;

    return 0;
}