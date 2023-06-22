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
    int maxProfit(vector<int>& prices, int fee) {
        long long noStock = 0, haveStock = numeric_limits<int>::min();
        
        for (auto price: prices) {
            long long newNoStock = max(noStock, haveStock + price - fee);
            long long newHaveStock = max(haveStock, noStock - price);
            
            noStock = newNoStock;
            haveStock = newHaveStock;
        }
        
        return max(noStock, haveStock);
    }
};