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
    int maxProfit(int k, vector<int>& prices) {
        // int MOST_NEGATIVE_INT = numeric_limits<int>::min();
        int MOST_NEGATIVE_INT = -1001;
        
        vector<int> hasStocks;
        vector<int> noStocks;
        
        for (auto i = 0; i < k; i++) {
            hasStocks.push_back(MOST_NEGATIVE_INT);
            noStocks.push_back(MOST_NEGATIVE_INT);
        }
        hasStocks.push_back(MOST_NEGATIVE_INT);
        noStocks.push_back(0);
        
        
        int answer = 0;
        
        for (auto price: prices) {
            vector<int> prevHasStocks = vector<int>(hasStocks);
            vector<int> prevNoStocks = vector<int>(noStocks);
            
            for (auto i = k; i >= 0; i--) {
                noStocks[i] = max(noStocks[i], prevHasStocks[i] + price);
                answer = max(answer, noStocks[i]);
            }
            
            for (auto i = k - 1; i >= 0; i--) { 
                hasStocks[i] = max(hasStocks[i], prevNoStocks[i + 1] - price);                
                answer = max(answer, hasStocks[i]);
            }            
        }
        
        return answer;
    }
};

int main() {
    Solution soln;

    // int k = 2;
    // vector<int> prices = {2,4,1};
    int k = 2;
    vector<int> prices = {3,2,6,5,0,3};
    cout << soln.maxProfit(k, prices) << endl;

    return 0;
}