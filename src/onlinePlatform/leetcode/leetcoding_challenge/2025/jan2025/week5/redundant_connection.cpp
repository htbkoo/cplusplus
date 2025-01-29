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
private:
    vector<int> parents;
    vector<int> sizes;
    
    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }
    
    bool unionSet(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            // the edge is redundant
            // as the 2 nodes are already unioned
            return false;
        }
        
        if (sizes[x] < sizes[y]) {
            int temp = x;
            x = y;
            y = temp;
        }
        
        parents[y] = x;
        sizes[x] += sizes[y];
        return true;
    }
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> answer;
        
        parents = vector<int>();
        for (int i = 0; i < n; ++i) {
            parents.push_back(i);
        }
        sizes = vector<int>(n, 1);        
        
        for (auto edge: edges) {
            auto a = edge[0];
            auto b = edge[1];
            if (!unionSet(a - 1, b - 1)) {
                answer = {a, b};
            }
        }
        
        return answer;
    }
};
