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

const int UNINITIALIZED = -1;

class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        memo = vector<vector<long>>();
        for (int i = 0; i <= cost.size(); ++i) {
            memo.push_back(vector<long>(cost.size() + 1, UNINITIALIZED));
        }
        return findMin(0, 0, cost, time);
    }
    
private:
    vector<vector<long>> memo;
    
    long findMin(int i, int painted, vector<int>& cost, vector<int>& time) {
        if (painted >= cost.size()) {
            return 0;
        }
        
        if (i >= cost.size()) {
            return numeric_limits<int>::max();
        }
        
        if (memo[i][painted] == UNINITIALIZED) {
            memo[i][painted] = min(
                findMin(i + 1, painted, cost, time),
                cost[i] + findMin(i + 1, painted + 1 + time[i], cost, time)
            );
        }
        
        return memo[i][painted];
    }
};