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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        for (auto num: nums) {
            counter[num]++;
        }
        
        auto cmp = [&](int left, int right) { return counter[left] > counter[right]; };
        priority_queue<int, vector<int>, decltype(cmp)> elements(cmp);
        for (auto& [key, count]: counter) {
            elements.push(key);
            
            if (elements.size() > k) {
                elements.pop();
            }
        }
        
        vector<int> answer;
        while (elements.size() > 0) {
            answer.push_back(elements.top());
            elements.pop();
        }
        
        return answer;
        // no this does not exist, https://stackoverflow.com/questions/40709286/c-how-to-copy-elements-from-stdpriority-queue-to-stdvector
        // return vector<int>(elements.begin(), elements.end());
    }
    
};
