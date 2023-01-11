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
    int minDeletionSize(vector<string>& strs) {
        int answer = 0;
        for (int x = 0; x < strs[0].size(); x++) {
            if (!isSorted(strs, x)) {
                answer++;
            }
        }
        return answer;
    }
    
private:
    bool isSorted(vector<string>& strs, int x) {
        if (strs.size() == 0) {
            // assume empty means sorted
            return true;
        }
        
        char prevCh = strs[0][x];
        for (int y = 1; y < strs.size(); y++) {
            if (strs[y][x] < prevCh) {
                return false;
            }
            prevCh = strs[y][x];
        }
        return true;
    }
};