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
    int numWaterBottles(int numBottles, int numExchange) {
        int empty = 0;
        int drank = 0;
        while (numBottles > 0) {
            drank += numBottles;
            empty += numBottles;
            numBottles = 0;

            numBottles += empty / numExchange;
            empty -= numBottles * numExchange;
        }

        return drank;
    }
};
