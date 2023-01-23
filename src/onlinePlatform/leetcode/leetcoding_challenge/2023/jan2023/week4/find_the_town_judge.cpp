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
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<unordered_set<int>> trustedFor = vector<unordered_set<int>>(n + 1);
        
        unordered_set<int> candidates;
        for (int i = 1; i <= n; i++) {
            candidates.insert(i);
        }
        
        for (auto relationship: trust) {
            int a = relationship[0], b = relationship[1];
            candidates.erase(a);
            
            trustedFor[b].insert(a);
        }
        
        int NO_JUDGE = -1;
        if (candidates.size() != 1) {
            return NO_JUDGE;
        }
        
        int possibleJudge = *(candidates.begin());
        if (trustedFor[possibleJudge].size() == n - 1) {
            return possibleJudge;
        } else {
            return NO_JUDGE;
        }
    }
};

int main() {
    Solution soln;

    vector<vector<int>> trust = {{1,2}};
    cout << soln.findJudge(2, trust) << endl;
    return 0;
}
