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
#include <numeric>
using namespace std; // since cin and cout are both in namespace std, this saves some text

const int MAX_BIT = 16384;  // 2 ** (7 * 2)
const int UNINITIALIZED = -1;

class Solution {
public:
    int maxScore(vector<int>& nums) {
        memset(memo, UNINITIALIZED, sizeof(memo));
        
        return findMax(nums, 0);
    }
    
private:
    int memo[MAX_BIT + 1];
    
    int findMax(vector<int>& nums, int bits) {
        if (isAllUsed(nums, bits)) {
            return 0;
        }
        
        if (memo[bits] != UNINITIALIZED) {
            return memo[bits];
        }
        
        vector<int> candidates;
        for (int i = 0; i < nums.size(); i++) {
            if (!isUsed(bits, i)) {
                candidates.push_back(i);
            }
        }
        
        int multiplier = 1 + (nums.size() - candidates.size()) / 2;
        for (int i = 0; i < candidates.size(); ++i) {
            int xIdx = candidates[i];
            int x = nums[xIdx];
            for (int j = i + 1; j < candidates.size(); ++j) {
                int yIdx = candidates[j];
                int y = nums[yIdx];
                
                int score = multiplier * gcd(x, y);
                int newBits = setUsed(setUsed(bits, xIdx), yIdx);
                memo[bits] = max(
                    memo[bits],
                    score + findMax(nums, newBits)
                );
            }
        }
        
        return memo[bits];
    }
    
    int isUsed(int bits, int i) {
        return (((int) pow(2, i)) & bits) > 0;
    }
    
    int setUsed(int bits, int i) {        
        return ((int) pow(2, i)) | bits;
    }
    
    int isAllUsed(vector<int>& nums, int bits) {
        return bits == ((int) pow(2, nums.size()) - 1);
    }

};