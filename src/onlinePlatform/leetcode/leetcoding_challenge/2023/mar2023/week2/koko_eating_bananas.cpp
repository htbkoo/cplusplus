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
    int minEatingSpeed(vector<int>& piles, int h) {
        // TODO: what if h is non-positive? what if piles is empty?

        int lo = 1, hi = *max_element(piles.begin(), piles.end());
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (canEatAll(mid, piles, h)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        return lo;
    }
    
private:
    bool canEatAll(int k, vector<int>& piles, int h) {
        // TODO: validate k must be positive
        
        for (int pile: piles) {
            int numHoursNeeded = (pile + k - 1) / k;
            h -= numHoursNeeded;
            if (h < 0) {
                return false;
            }
        }
            
        return true;
    }
};