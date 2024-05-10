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
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<tuple<double, int, int>, vector<tuple<double, int, int>>, greater<tuple<double, int, int>>> pq;

        for (int i = 1; i < arr.size(); ++i) {
            int numerator = arr[0];
            int denominator = arr[i];
            pq.push(tuple{(double) numerator / (double) denominator, 0, i});
        }

        for (int x = 1; x < k; ++x) {
            auto [_, i, j] = pq.top();
            pq.pop();

            if (i < j) {
                pq.push({(double) arr[i + 1] / (double) arr[j], i + 1, j});
            }
        }

        auto [_, i, j] = pq.top();

        return {arr[i], arr[j]};
    }
};
