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
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> needs(rocks.size());
        
        for (int i = 0; i < rocks.size(); i++) {
            needs[i] = capacity[i] - rocks[i];
        }
        
        sort(needs.begin(), needs.end());
        
        int answer = 0;
        while (answer < rocks.size()) {
            if (additionalRocks < needs[answer]) {
                break;
            }
            additionalRocks -= needs[answer];
            answer++;
        }
        return answer;
    }
};

int main() {
    Solution soln;
    vector<int> capacity = {2,3,4,5}, rocks = {1,2,4,4};
    int additionalRocks = 2;

    cout << soln.maximumBags(capacity, rocks, additionalRocks) << endl;
}