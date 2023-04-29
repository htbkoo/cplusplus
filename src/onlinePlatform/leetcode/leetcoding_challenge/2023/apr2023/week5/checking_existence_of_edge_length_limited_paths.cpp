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
#include <cstring> // for memset
using namespace std; // since cin and cout are both in namespace std, this saves some text

const int MAX_NUM_NODES = 1e5;

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        for (int i = 0; i < n; ++i) {
            parents[i] = i;
        }
        
        // TODO: assume we can mutae queries
        for (int q = 0; q < queries.size(); ++q) {
            queries[q].push_back(q);
        }
        sort(queries.begin(), queries.end(), [](vector<int>& queryA, vector<int>& queryB){return queryA[2] < queryB[2];});
        
        vector<bool> answers;
        return answers;
    }
    
private:
    int parents[MAX_NUM_NODES + 1];
};

int main() {
    Solution soln;
    int n = 5;
    vector<vector<int>> edgeList = {{0,1,10},{1,2,5},{2,3,9},{3,4,13}};
    vector<vector<int>> queries = {{0,4,14},{1,4,13}};

    auto answers = soln.distanceLimitedPathsExist(n, edgeList, queries);

    return 0;
}