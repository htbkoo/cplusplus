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

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> edgesByType = {{}, {}, {}, {}};
        
        for (auto edge: edges) {
            int type = edge[0], u = edge[1], v = edge[2];
            edgesByType[type].push_back(pair{u, v});
        }
        
        
        
    }
};