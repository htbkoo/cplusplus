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


class Solution {
public:
    int numSquares(int n) {
        vector<int> counts = vector<int>(n + 1);
        counts[0] = 0;
        counts[1] = 1;
        
        unordered_set<int> perfectSquares;
        perfectSquares.insert(1);
        
        for (int i = 2; i <= n; i++) {
            if (isPerfectSquare(i)) {
                perfectSquares.insert(i);
            }
            
            counts[i] = numeric_limits<int>::max();
            for (int p: perfectSquares) {
                counts[i] = min(counts[i], counts[i - p] + 1);
            }
        }
        
        return counts[n];
    }
    
private:
    bool isPerfectSquare(int x) {
        int s = (int) sqrt(x);
        return s * s == x;
    }
};
