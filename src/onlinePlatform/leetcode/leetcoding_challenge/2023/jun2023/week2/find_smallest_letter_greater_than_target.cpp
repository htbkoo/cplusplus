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
    char nextGreatestLetter(vector<char>& letters, char target) {
        int lo = 0;
        int hi = letters.size() - 1;
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (letters[mid] > target){
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        if (letters[lo] > target) {
            return letters[lo];
        } else {
            return letters[0];
        }
    }
};