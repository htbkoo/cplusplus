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
    int longestSubsequence(vector<int>& arr, int difference) {
        int answer = 0;
        unordered_map<int, int> prevLengths;
        
        for (auto num: arr) {
            int prevNum = num - difference;
            
            int newLength = (prevLengths.count(prevNum) > 0) ? (prevLengths[prevNum] + 1) : 1;
                
            if (prevLengths.count(num) == 0) {
                prevLengths[num] = 1;
            }
            
            prevLengths[num] = max(prevLengths[num], newLength); 
            answer = max(answer, prevLengths[num]);
        }        
        
        return answer;
    }
};
