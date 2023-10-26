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

const int MOD = 1e9 + 7;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        // what if there is 1 in arr? it can go infinite
        
        memo = unordered_map<int, int>();
        nums = unordered_set<int>(begin(arr), end(arr));
        
        int answer = 0;
        for (auto num: arr) {
            answer = (answer + count(num)) % MOD;
        }
        return answer;
    }
    
private:
    unordered_map<int, int> memo;
    unordered_set<int> nums;
    
    int count(int num) {
        if (memo.count(num) == 0) {
            memo[num] = 1;  // with only num as root
            
            for (auto factor: nums) {
                if (num % factor == 0 and nums.count(num / factor) > 0) {
                    memo[num] = (memo[num] + ((long) count(factor) * (long) count(num / factor)) % MOD) % MOD;
                }
            }
            
        }
        return memo[num];
    }
};