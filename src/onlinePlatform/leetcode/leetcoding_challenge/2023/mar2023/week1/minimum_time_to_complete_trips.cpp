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
    long long minimumTime(vector<int>& time, int totalTrips) {
        int maxTime = *max_element(time.begin(), time.end());
        
        long long lo = 0, hi = (long long) maxTime * (long long) totalTrips;
        
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            
            if (canComplete(mid, time, totalTrips)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        return lo;
    }
    
private:
    bool canComplete(long long mid, vector<int>& time, int totalTrips) {
        for (auto t: time) {
            long long numTrip = mid / (long long) t;
            if (numTrip >= (long long) totalTrips) {
                return true;
            } else {
                totalTrips -= (int) numTrip;
            }
        }
        return false;
    }
};