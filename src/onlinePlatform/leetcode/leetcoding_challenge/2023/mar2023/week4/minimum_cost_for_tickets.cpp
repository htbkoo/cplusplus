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
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memo = unordered_map<int, int>();
        passes = unordered_map<int, int>();
        
        vector<int> DAYS{1, 7, 30};
        for (int i = 0; i < DAYS.size(); i++) {
            int day = DAYS[i];
            int cost = costs[i];
            passes[day] = cost;
        }
        
        return findMin(0, days);
    }
    
private:
    unordered_map<int, int> memo;
    unordered_map<int, int> passes;
    
    int findMin(int i, vector<int>& days) {
        if (memo.count(i) > 0) {
            return memo[i];
        }
        if (i >= days.size()) {
            return 0;
        }
        
        int currDay = days[i];
        int minCost = numeric_limits<int>::max();
        for (auto& [day, cost]: passes) {
            int nextIndex = distance(days.begin(), lower_bound(days.begin(), days.end(), currDay + day));
            minCost = min(
                minCost,
                cost + findMin(nextIndex, days)
            );
        }
        memo[i] = minCost;
        return memo[i];
    }
};

class WASolution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memo = unordered_map<int, long>();
        passes = unordered_map<int, int>();
        
        vector<int> DAYS{1, 7, 30};
        for (int i = 0; i < DAYS.size(); i++) {
            int day = DAYS[i];
            int cost = costs[i];
            passes[day] = cost;
        }
        
        return findMin(0, days);
    }
    
private:
    unordered_map<int, long> memo;
    unordered_map<int, int> passes;
    
    int findMin(int i, vector<int>& days) {
        if (memo.count(i) > 0) {
            return memo[i];
        }
        memo[i] = numeric_limits<int>::max();
        
        if (i >= days.size()) {
            return 0;
        }
        
        int currDay = days[i];
        for (auto& [day, cost]: passes) {
            int nextIndex = distance(days.begin(), lower_bound(days.begin(), days.end(), currDay + day));
            memo[i] = min(
                memo[i],
                (long) cost + findMin(nextIndex, days)
            );
        }
        return memo[i];
    }
};
