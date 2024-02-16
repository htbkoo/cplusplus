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
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> counter;
        for (auto num: arr) {
            if (counter.count(num) == 0) {
                counter[num] = 0;
            }
            counter[num]++;
        }


        vector<int> allCounts;
        for (auto &[_, count]: counter) {
            allCounts.push_back(count);
        }

        sort(begin(allCounts), end(allCounts));

        for (int i = 0; i < allCounts.size(); ++i) {
            if (allCounts[i] > k) {
                return allCounts.size() - i;
            }
            k -= allCounts[i];
        }
        return 0;
    }
};