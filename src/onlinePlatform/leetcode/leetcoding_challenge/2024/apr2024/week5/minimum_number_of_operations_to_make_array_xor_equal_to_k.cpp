#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <limits>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iterator>
#include <sstream>
#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int INT_NUM_BITS = 32;
        
        vector<int> bitCounts(INT_NUM_BITS, 0);
        
        for (auto num: nums) {
            for (int i = 0; i < INT_NUM_BITS; ++i) {
                bitCounts[i] += num % 2;
                num /= 2;
            }
        }
        
        int answer = 0;
        for (int i = 0; i < INT_NUM_BITS; ++i) {
            if (bitCounts[i] % 2 != k % 2) {
                answer++;
            };
            k /= 2;
        }
        
        return answer;
    }
};
