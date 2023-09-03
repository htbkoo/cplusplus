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
    int uniquePaths(int m, int n) {
        if (m < n) {
            int temp = m;
            m = n;
            n = temp;
        }
    
        vector<int> count(n, 1);
        
        for (int i = 1; i < m; ++i) {
            vector<int> nextCount(n, 0);
            nextCount[0] = 1;
            
            for (int j = 1; j < n; ++j) {
                nextCount[j] = nextCount[j - 1] + count[j];
            }
            
            count = nextCount;
        }
        
        return count.back();
    }
};