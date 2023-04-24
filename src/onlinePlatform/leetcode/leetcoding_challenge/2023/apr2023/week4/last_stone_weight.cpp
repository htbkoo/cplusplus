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

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        
        while (pq.size() > 1) {
            int first = pq.top();
            pq.pop();
            
            int second = pq.top();
            pq.pop();
            
            if (first != second) {
                pq.push(first - second);
            }
        }
        
        if (pq.size() == 0) {
            return 0;
        } else {
            return pq.top();
        }
    }
};