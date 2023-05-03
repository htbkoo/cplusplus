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
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set set1(nums1.begin(), nums1.end());
        unordered_set set2(nums2.begin(), nums2.end());
        
        vector<vector<int>> answer;
        
        for (auto& [setPresent, setAbsent]: {pair{set1, set2}, pair{set2, set1}}) {
            vector<int> nums;
            for (auto num: setPresent) {
                if (setAbsent.count(num) == 0) {
                    nums.push_back(num);
                }
            }
            answer.push_back(nums);
        }
        
        return answer;
    }
};