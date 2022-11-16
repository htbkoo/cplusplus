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

int guess(int num);

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int lo = 1;
        int hi = n;
        
        while (lo < hi) {
            // int mid = (lo + hi) / 2;  // TODO: confirm the valid of mid
            int mid = lo + (hi - lo) / 2;  // TODO: confirm the valid of mid
            int result = guess(mid);
            
            if (result == 1) {
                lo = mid + 1;
            } else if (result == -1) {
                hi = mid - 1;
            } else if (result == 0) {
                return mid;
            } else {
                throw invalid_argument("invalid guess result: " + to_string(result));
            }
        }
        
        return lo;
    }
};