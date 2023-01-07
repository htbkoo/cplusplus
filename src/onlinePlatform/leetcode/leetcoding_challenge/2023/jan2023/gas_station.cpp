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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        long totalGas = sum(gas);
        long totalCost = sum(cost);
        
        int IMPOSSIBLE = -1;
        if (totalGas < totalCost) {
            return IMPOSSIBLE;
        }
        
        int answer = 0;
        int remainGas = 0;
        for (int i = 0; i < gas.size(); i++) {
            remainGas += (gas[i] - cost[i]);
            if (remainGas < 0) {
                answer = i + 1;
                remainGas = 0;
            }            
        }
        return answer;
    }
    
private:
    long sum(vector<int>& v) {
        long total = 0;
        for (int n: v) {
            total += n;
        }
        return total;
    }
};

class WASolution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        long totalGas = sum(gas);
        long totalCost = sum(cost);
        
        int IMPOSSIBLE = -1;
        if (totalGas < totalCost) {
            return IMPOSSIBLE;
        }
        
        int maxSurplusIndex = 0;
        for (int i = 1; i < gas.size(); i++) {
            int prevSurplus = gas[maxSurplusIndex] - cost[maxSurplusIndex];
            int currSurplus = gas[i] - cost[i];
            if (currSurplus > prevSurplus) {
                maxSurplusIndex = i;
            }
        }
        return maxSurplusIndex;
    }
    
private:
    long sum(vector<int>& v) {
        long total = 0;
        for (int n: v) {
            total += n;
        }
        return total;
    }
};
