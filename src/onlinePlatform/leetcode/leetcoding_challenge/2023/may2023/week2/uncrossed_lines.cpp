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
#include <cstring> // for memset
using namespace std; // since cin and cout are both in namespace std, this saves some text

const int MAX_NUMS_LENGTH = 500;
const int UNINITIALIZED = -1;

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(memo, UNINITIALIZED, sizeof(memo));
        
        unordered_map<int, vector<int>> positions;
        for (int i = 0; i < nums2.size(); ++i) {
            int num = nums2[i];
            positions[num].push_back(i);
        }        
        
        return findMax(nums1, nums2, positions, 0, 0);
    }
    
private:
    int memo[MAX_NUMS_LENGTH + 1][MAX_NUMS_LENGTH + 1];
    
    int findMax(vector<int>& nums1, vector<int>& nums2, unordered_map<int, vector<int>>& positions, int i, int j) {
        if (i >= nums1.size() || j >= nums2.size()) {
            return 0;
        }
        
        if (memo[i][j] != UNINITIALIZED) {
            return memo[i][j];
        }
        
        // just skipping the curr num
        memo[i][j] = max(
            findMax(nums1, nums2, positions, i, j + 1), 
            max(
                findMax(nums1, nums2, positions, i + 1, j), 
                findMax(nums1, nums2, positions, i + 1, j + 1)
            )
        );
        
        int num = nums1[i];
        auto it = lower_bound(positions[num].begin(), positions[num].end(), j);
        if (it != positions[num].end()) {
            int idx = distance(positions[num].begin(), it);
            int newJ = positions[num][idx] + 1;
            memo[i][j] = max(
                memo[i][j],
                1 + findMax(nums1, nums2, positions, i + 1, newJ)
            );
        }
        
        return memo[i][j];
    }
};

int main() {
    Solution soln;
    vector<int> nums1 = {2,5,1,2,5}, nums2 = {10,5,2,1,5,2};

    cout << soln.maxUncrossedLines(nums1, nums2) << endl;

    return 0;
}