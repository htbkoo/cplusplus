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
    bool canMakeArithmeticProgression(vector<int>& arr) {
        // TODO: clone arr to avoid mutating arr
        sort(arr.begin(), arr.end());
        
        // TODO: confirm what if arr.size() < 2
        
        int diff = arr[1] - arr[0];
        for (int i = 2; i < arr.size(); ++i) {
            if ((arr[i] - arr[i - 1]) != diff) {
                return false;
            }
        }
        
        return true;
    }
};