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
    int shipWithinDays(vector<int>& weights, int days) {
        // TODO: clarify, what if weights is empty? all weights positive? what if days <= 0? weight is integral?
        
        long totalSumWeights = sum(weights);
        
        long lo = *max_element(weights.begin(), weights.end());
        long hi = totalSumWeights;
            
        while (lo < hi) {
            long mid = lo + (hi - lo) / 2;
            
            if (canShip(mid, weights, days)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        return lo;
    }

private:
    long sum(vector<int>& weights) {
        long total = 0;
        for (auto weight: weights) {
            total += weight;
        }
        return total;
    }

    bool canShip(long capacity, vector<int>& weights, int days) {
        long remain = 0;
        for (auto weight: weights) {
            if (weight > remain) {
                if (days > 0) {
                    days--;
                    
                    if (capacity < weight) {
                        throw invalid_argument("bug"); 
                    }
                    
                    remain = capacity;
                } else {
                    return false;
                }
            }
            
            remain -= weight;
        }
        return true;
    }
};