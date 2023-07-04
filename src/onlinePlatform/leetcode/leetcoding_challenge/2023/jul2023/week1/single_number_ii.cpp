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
    int singleNumber(vector<int>& nums) {
        const int EVERY_APPEARANCE = 3;
        
        vector<int> bits(32, 0);
        
        for (auto num: nums) {
            if (num < 0) {
                bits[0] = (bits[0] + 1) % EVERY_APPEARANCE;
                num = 2147483647 + num + 1;
            }
            
            int i = 31;
            while (num > 0 && i >= 1) {
                if (num % 2 == 1) {
                    bits[i] = (bits[i] + 1) % EVERY_APPEARANCE;
                }
                num /= 2;
                i--;
            }            
        }
        
        int answer = 0;
        int base = 1;
        for (int i = 31; i >= 1; --i) {
            if (bits[i] > 0) {
                answer += base;                
            }
            if (i > 1) {
                base *= 2;
            }
        }
        
        if (bits[0] == 0) {
            return answer;
        } else {
            return answer - 2147483647 - 1;
        }
    }
};

class WASolution {
public:
    int singleNumber(vector<int>& nums) {
        const int EVERY_APPEARANCE = 3;
        
        vector<int> bits(32, 0);
        
        for (auto num: nums) {
            if (num < 0) {
                bits[0] = (bits[0] + 1) % EVERY_APPEARANCE;
                num = !(num + 1);
            }
            
            int i = 31;
            while (num > 0) {
                if (num % 2 == 1) {
                    bits[i] = (bits[i] + 1) % EVERY_APPEARANCE;

                    cout << i << ": " << bits[i] << endl;
                }
                num /= 2;
                i--;
            }            
        }
        
        int answer = 0;
        int base = 1;
        for (int i = 31; i >= 1; --i) {
            if (bits[i] > 0) {
                answer += base;                
            }
            if (i > 1) {
                base *= 2;
            }
        }
        
        if (bits[0] == 0) {
            return answer;
        } else {
            return -answer;
        }
    }
};

int main() {
    Solution soln;

    // vector<int> nums{2,2,3,2};
    vector<int> nums{-2,-2,1,1,4,1,4,4,-4,-2};

    cout << soln.singleNumber(nums) << endl;

    return 0;
}