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

const int MAX_NUM_NODES = 100; 
const int UNGROUPED = -1;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // unordered_map<int, unordered_set<int>> neighbours;
        // for (auto edge: graph) {
        //     int u = edge[0];
        //     int v = edge[1];
        //     neighbours[u].insert(v);
        //     neighbours[v].insert(u);
        // }
        
        // int groups[MAX_NUM_NODES + 1];
        // int groups[graph.size() - 1];
        // memset(groups, UNGROUPED, sizeof(groups));
        vector<int> groups(graph.size(), UNGROUPED);
        
        for (int i = 0; i < graph.size(); i++) {
            if (groups[i] == UNGROUPED) {
                if (!dfs(i, graph, groups, 0)) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
private:
    bool dfs(int i, vector<vector<int>>& graph, vector<int>& groups, int group) {
        if (groups[i] != UNGROUPED) {
            return groups[i] == group;
        }
        groups[i] = group;
        
        for (auto nextNode: graph[i]) {
            if (!dfs(nextNode, graph, groups, 1 - group)) {
                return false;
            }
        }
        return true;
    }
};