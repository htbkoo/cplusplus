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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }
        
        unordered_map<int, unordered_set<int>> neighbours;
        for (auto& connection: connections) {
            int a = connection[0], b = connection[1];
            neighbours[a].insert(b);
            neighbours[b].insert(a);
        }
        
        int numGroups = 0;
        unordered_set<int> visited;
        for (int i = 0; i < n; i++) {
            numGroups += dfs(i, visited, neighbours);
        }
        
        return numGroups - 1;
    }
    
private:
    int dfs(int i, unordered_set<int>& visited, unordered_map<int, unordered_set<int>>& neighbours) {
        if (visited.count(i) > 0) {
            return 0;
        }
        visited.insert(i);
        
        for (auto& nextNode: neighbours[i]) {
            dfs(nextNode, visited, neighbours);
        }
            
        return 1;
    }
};