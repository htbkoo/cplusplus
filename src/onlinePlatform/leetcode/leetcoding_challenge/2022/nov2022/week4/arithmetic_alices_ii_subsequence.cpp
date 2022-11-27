#include <algorithm>
#include <cmath>
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
    int numberOfArithmeticSlices(vector<int>& nums) {
        int answer = 0;        
        vector<unordered_map<long, int>> unfulfilled = vector<unordered_map<long, int>>(nums.size());
        vector<unordered_map<long, int>> fulfilled = vector<unordered_map<long, int>>(nums.size());

        for (int curr = 0; curr < nums.size(); curr++) {
            for (int prev = 0; prev < curr; prev++) {
                long diff = (long) nums[curr] - (long) nums[prev];

                if (fulfilled[curr].count(diff) == 0) {
                    fulfilled[curr][diff] = 0;
                }
                if (unfulfilled[curr].count(diff) == 0) {
                    unfulfilled[curr][diff] = 0;
                }
                if (fulfilled[prev].count(diff) == 0) {
                    fulfilled[prev][diff] = 0;
                }
                if (unfulfilled[prev].count(diff) == 0) {
                    unfulfilled[prev][diff] = 0;
                }
                int added = fulfilled[prev][diff] + unfulfilled[prev][diff];
                fulfilled[curr][diff] += added;
                unfulfilled[curr][diff]++;

                answer += added;
            }
        }

        return answer;
    }
};

class TLESolution2 {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int answer = 0;        
        vector<unordered_map<long, int>> unfulfilled = vector<unordered_map<long, int>>(nums.size());
        vector<unordered_map<long, int>> fulfilled = vector<unordered_map<long, int>>(nums.size());

        for (int curr = 0; curr < nums.size(); curr++) {
            for (int prev = 0; prev < curr; prev++) {
                long diff = (long) nums[curr] - (long) nums[prev];

                if (fulfilled[curr].count(diff) == 0) {
                    fulfilled[curr][diff] = 0;
                }
                if (unfulfilled[curr].count(diff) == 0) {
                    unfulfilled[curr][diff] = 0;
                }
                if (fulfilled[prev].count(diff) == 0) {
                    fulfilled[prev][diff] = 0;
                }
                if (unfulfilled[prev].count(diff) == 0) {
                    unfulfilled[prev][diff] = 0;
                }
                int added = fulfilled[prev][diff] + unfulfilled[prev][diff];
                fulfilled[curr][diff] += added;
                unfulfilled[curr][diff]++;

                answer += added;
            }
        }

        return answer;
    }
};

class TLESolution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        long answer = 0;        
        vector<unordered_map<long, long>> unfulfilled = vector<unordered_map<long, long>>(nums.size());
        vector<unordered_map<long, long>> fulfilled = vector<unordered_map<long, long>>(nums.size());

        for (int curr = 0; curr < nums.size(); curr++) {
            for (int prev = 0; prev < curr; prev++) {
                long diff = (long) nums[curr] - (long) nums[prev];

                if (fulfilled[curr].count(diff) == 0) {
                    fulfilled[curr][diff] = 0;
                }
                if (unfulfilled[curr].count(diff) == 0) {
                    unfulfilled[curr][diff] = 0;
                }
                if (fulfilled[prev].count(diff) == 0) {
                    fulfilled[prev][diff] = 0;
                }
                if (unfulfilled[prev].count(diff) == 0) {
                    unfulfilled[prev][diff] = 0;
                }
                long added = fulfilled[prev][diff] + unfulfilled[prev][diff];
                fulfilled[curr][diff] += added;
                unfulfilled[curr][diff]++;

                answer += added;
            }
        }

        return answer;
    }
};


int main() {
    Solution soln;
    
    // vector<int>  nums= {3,3,5,7};  // 2
    // vector<int>  nums= {7,7,7,7,7};  // 16
    // vector<int>  nums= {7,7,7,7,7,7};  // 42
    vector<int>  nums= {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};  // 2096920
    cout << soln.numberOfArithmeticSlices(nums) << endl;
    return 0;
}