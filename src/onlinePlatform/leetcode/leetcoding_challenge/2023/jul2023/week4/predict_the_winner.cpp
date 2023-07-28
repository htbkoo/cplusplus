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

// const int MAX_NUM_LENGTH = 20;

const int UNINITIALIZED = numeric_limits<int>::min();

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        memo = vector<vector<vector<int>>>();
        for (int i = 0; i <= nums.size(); ++i) {
            memo.push_back(vector<vector<int>>());
            for (int j = 0; j <= nums.size(); ++j) {
                memo[i].push_back(vector<int>(2, UNINITIALIZED));
            }
        }
        
        int START_PLAYER = 0;
        
        auto result = calc(nums, 0, nums.size() - 1, START_PLAYER);
        
        return result >= 0;
    }
    
private:
    vector<vector<vector<int>>> memo;
    
    int calc(vector<int>& nums, int i, int j, int player) {
        if (i > j) {
            return 0;
        }

        if (memo[i][j][player] == UNINITIALIZED) {
            if (player == 0) {
                memo[i][j][player] = max(
                    nums[i] + calc(nums, i + 1, j, 1 - player),
                    nums[j] + calc(nums, i, j - 1, 1 - player)
                );
            } else if (player == 1) {
                memo[i][j][player] = min(
                    -nums[i] + calc(nums, i + 1, j, 1 - player),
                    -nums[j] + calc(nums, i, j - 1, 1 - player)
                );
            } else {
                throw invalid_argument("expected player to be 0 or 1 but was: " + to_string(player));
            }
        }
        
        return memo[i][j][player];
    }
};