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
    int buyChoco(vector<int>& prices, int money) {
        int leftover = -1;

        for (int i = 0; i < prices.size(); ++i) {
            for (int j = i + 1; j < prices.size(); ++j) {
                if (prices[i] + prices[j] <= money) {
                    leftover = max(
                        leftover,
                        money - (prices[i] + prices[j])
                    );
                }
            }
        }

        if (leftover == -1) {
            return money;
        } else {
            return leftover;
        }
    }
};