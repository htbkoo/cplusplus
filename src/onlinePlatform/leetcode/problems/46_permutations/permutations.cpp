#include <algorithm>
#include <vector>
#include <set>
#include <limits>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <sstream>
#include <queue>
#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 1) {
            // return {{nums[0]}};
            return {nums};
        }
        
        vector<vector<int>> answer;
        for (int i = 0; i < nums.size(); i++) {
            vector<int> head = {nums[i]};
            vector<int> remainNums = getRemainNums(nums, i);
            auto tails = permute(remainNums);
            for (auto& tail: tails) {
                vector<int> v = concat(head, tail);
                answer.push_back(v);
            }
        }
        return answer;
    }
    
private:
    vector<int> getRemainNums(vector<int>& nums, int without) {
        vector<int> remainNums;
        for (int i = 0; i < nums.size(); i++) {
            if (i != without) {
                remainNums.push_back(nums[i]);
            }
        }
        return remainNums;
    }
    
    vector<int> concat(vector<int> a, vector<int> b) {
        vector<int> v(a);
        v.insert(v.end(), b.begin(), b.end());
        return v;
    }
};

