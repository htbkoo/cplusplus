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
    int findLongestChain(vector<vector<int>>& pairs) {
        if (pairs.size() == 0) {
            return 0;
        }
        
        sort(pairs.begin(), pairs.end(), [](auto& pair1, auto& pair2) { return pair1[1] < pair2[1]; });
        
        vector<int> ends = {numeric_limits<int>::min()};
        vector<int> lengths = {0};
        
        for (auto pair: pairs) {
            int start = pair[0], end = pair[1];
            ends.push_back(end);
            
            int length = max(
                lengths.back(),
                1 + lengths[distance(ends.begin(), lower_bound(ends.begin(), ends.end(), start)) - 1]
            );
            lengths.push_back(length);
        }
        
        return lengths.back();        
    }
};

int main() {
    Solution soln;

    // vector<vector<int>> pairs = {{1,2},{2,3},{3,4}};
    vector<vector<int>> pairs = {{9,10},{9,10},{4,5},{-9,-3},{-9,1},{0,3},{6,10},{-5,-4},{-7,-6}};

    cout << soln.findLongestChain(pairs) << endl;

    return 0;
}