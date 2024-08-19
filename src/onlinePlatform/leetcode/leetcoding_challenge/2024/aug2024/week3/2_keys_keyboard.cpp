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

int UNINITIALIZED = numeric_limits<int>::max();
class Solution {
public:
    int minSteps(int n) {
        memo = vector<vector<long long>>(n + 1, vector<long long>(n + 1, UNINITIALIZED));
        return findMin(n, 1, 0);
    }
    
private:
    vector<vector<long long>> memo;
    
    int findMin(int n, int size, int copySize) {
        if (size > n || copySize > n) {
            return numeric_limits<int>::max();
        }
        if (size == n) {
            return 0;
        }
            
        if (memo[size][copySize] == UNINITIALIZED) {
            if (size > copySize) {
                memo[size][copySize] = min(
                    memo[size][copySize],
                    1 + (long long) findMin(n, size, size)
                ); // copy
            }
            
            if (copySize > 0) {
                memo[size][copySize] = min(
                    memo[size][copySize],
                    1 + (long long) findMin(n, size + copySize, copySize)
                ); // paste
            }
        }
        return memo[size][copySize];
    }
};
