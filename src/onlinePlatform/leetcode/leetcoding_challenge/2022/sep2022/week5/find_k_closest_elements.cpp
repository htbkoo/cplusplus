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
#include <string>
#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // TODO: validate input, e.g. handle k larger than arr.size()
        
        auto it = lower_bound(arr.begin(), arr.end(), x);
        
        if (it == arr.begin()) {
            return vector<int>(it, it + k);
        } else if (it == arr.end()) {
            return vector<int>(it - k, it);
        } else {
            auto lo = it;
            auto hi = it;
            
            while (distance(lo, hi) < k && (lo != arr.begin() || hi != arr.end())) {
                if (lo == arr.begin()) {
                    hi++;
                    continue;
                }
                if (hi == arr.end()) {
                    lo--;
                    continue;
                }

                if (abs(x - *(lo - 1)) <= abs(x - *hi)) {
                    lo--;
                    continue;
                } else {
                    hi++;
                    continue;
                }
            }

            return vector<int>(lo, hi);
        }
    }
};

class WASolution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // TODO: validate input, e.g. handle k larger than arr.size()
        
        auto it = lower_bound(arr.begin(), arr.end(), x);
        
        if (it == arr.begin()) {
            return vector<int>(it, it + k);
        } else if (it == arr.end()) {
            return vector<int>(it - k, it);
        } else {
            auto lo = it;
            auto hi = it + 1;
            if (abs(x - *(it - 1)) <= abs(x - *(it))) {
                lo = it - 1;
                hi = it;
            }
            
            while (distance(lo, hi) < k && (lo != arr.begin() || hi != arr.end())) {
                if (lo == arr.begin()) {
                    hi++;
                    continue;
                }
                if (hi == arr.end()) {
                    lo--;
                    continue;
                }

                if (abs(x - *lo) <= abs(x - *hi)) {
                    lo--;
                    continue;
                } else {
                    hi++;
                    continue;
                }
            }

            return vector<int>(lo, hi);
        }

        
    }
};

int main() {
    Solution soln;
    vector<int> arr = {10,20,30,40,50};
    soln.findClosestElements(arr, 4, 30);
    soln.findClosestElements(arr, 4, -1);
    // vector<int> arr = {0,0,1,2,3,3,4,7,7,8};
    // vector<int> arr = {0,0,0,1,3,5,6,7,8,8};
    // soln.findClosestElements(arr, 2, 2);
    // cout << soln.findClosestElements(arr, 4, 3) << endl;

    return 0;
}