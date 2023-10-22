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
    int maximumScore(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        if (k > 0) {
            pq.push(pair{nums[k - 1], k - 1});
        }
        if (k < nums.size() - 1) {
            pq.push(pair{nums[k + 1], k + 1});
        }
        
        int answer = nums[k];
        int minNum = nums[k];
        int lo = k;
        int hi = k;
        while (pq.size() > 0) {
            auto [num, idx] = pq.top();
            pq.pop();
            
            minNum = min(minNum, num);
            
            if (idx > k) {
                hi = max(hi, idx);
                if (idx < nums.size() - 1) {                    
                    pq.push(pair{nums[idx + 1], idx + 1});
                }
            }
            if (idx < k) {
                lo = min(lo, idx);
                if (idx > 0) {
                    pq.push(pair{nums[idx - 1], idx - 1});
                }
            }
            
            answer = max(answer, minNum * (hi - lo + 1));
        }
        
        return answer;
    }
};