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
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        
        int totalSum = 0;        
        for (int num: nums) {
            totalSum += num;
        }        
        int expectedSum = n * (1 + n) / 2;
        
        for (int i = 0; i < n; i++) {
            int num = abs(nums[i]);
            nums[num - 1] = -nums[num - 1];
        }
        
        vector<int> positives;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            if (num > 0) {
                positives.push_back(i + 1);
            }
        }    
        for (int &num: nums) {
            num = abs(num);
        }
        
        if (positives.size() == 2) {
            sort(positives.begin(), positives.end());
            int dup, missing;
            if (totalSum > expectedSum) {
                dup = positives[1];
                missing = positives[0];
            } else {
                dup = positives[0];
                missing = positives[1];
            }                
            return vector<int>{dup, missing};            
        } else {
            throw invalid_argument("bug"); 
        }
    }
};

class FirstSolution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int dup = -1;
        int missing = -1;
        
        unordered_set<int> appeared;        
        for (int num: nums) {
            if (appeared.count(num) > 0) {
                dup = num;
            }
            appeared.insert(num);
        }
        
        for (int i = 1; i <= nums.size(); i++) {
            if (appeared.count(i) == 0) {
                missing = i;
                break;
            }
        }
        
        return vector<int>{dup, missing};
    }
};