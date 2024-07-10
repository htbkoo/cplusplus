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
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long total = 0;
        int now = 0;

        for (auto &customer: customers) {
            auto arrival = customer[0];
            auto time = customer[1];

            now = max(now, arrival) + time;
            auto wait = now - arrival;
            total += wait;
        }

        return (double) total / (double) customers.size();
    }
};
