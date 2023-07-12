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
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size(), false);
        vector<bool> safe(graph.size(), true);
        
        
        for (int i = 0; i < graph.size(); ++i) {
            if (visited[i]) {
                continue;
            }
            unordered_set<int> path;
            dfs(i, path, graph, visited, safe);
        }
        
        vector<int> answer;
        for (int i = 0; i < graph.size(); ++i) {
            if (safe[i]) {
                answer.push_back(i);
            }
        }
        return answer;
    }
    
private:
    bool dfs(
        int node, 
        unordered_set<int>& path,
        vector<vector<int>>& graph,
        vector<bool>& visited,
        vector<bool>& safe
    ) {
        if (path.count(node) > 0) {
            safe[node] = false;
        }
        path.insert(node);
        
        if (visited[node]) {
            path.erase(node);
            return safe[node];
        }
        visited[node] = true;
        
        for (auto nextNode: graph[node]) {
            if (!dfs(nextNode, path, graph, visited, safe)) {
                safe[node] = false;
            }
        }
        
        path.erase(node);
        return safe[node];
    }
};