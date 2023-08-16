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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int> counter;
        for (int i = 0; i < k; ++i) {
            int num = nums[i];
            counter[num]++;
        }
        
        vector<int> answer;
        answer.push_back(counter.rbegin()->first);
        
        for (int i = k; i < nums.size(); ++i) {
            int num = nums[i];
            counter[num]++;
            
            int prevNum = nums[i - k];
            counter[prevNum]--;
            if (counter[prevNum] == 0) {
                counter.erase(prevNum);
            }
            
            answer.push_back(counter.rbegin()->first);
        }
        
        return answer;
    }
};