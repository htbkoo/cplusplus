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
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        
        int answer = 0;
        int lowest = prices[0];
        for (int price: prices) {
            lowest = min(lowest, price);
            int profit = price - lowest;
            answer = max(answer, profit);
        }
        return answer;
    }
};
