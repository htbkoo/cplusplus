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
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        
        for (auto num: nums) {
            pq.push(-num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        // TODO: validate input, what if nums.size() == 0 or k == 0?
        return -pq.top();
    }
};
