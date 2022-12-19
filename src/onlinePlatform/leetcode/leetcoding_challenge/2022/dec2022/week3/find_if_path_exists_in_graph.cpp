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
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> neighbours;
        for (auto edge: edges) {
            int u = edge[0], v = edge[1];
            neighbours[u].push_back(v);
            neighbours[v].push_back(u);
        }
        
        unordered_set<int> visited;
        return hasPath(source, destination, neighbours, visited);
    }
    
private:
    bool hasPath(int node, int destination, unordered_map<int, vector<int>>& neighbours, unordered_set<int>& visited) {
        if (node == destination) {
            return true;
        }
        if (visited.count(node) > 0) {
            return false;
        }
        visited.insert(node);
        
        for (int nextNode: neighbours[node]) {
            if (hasPath(nextNode, destination, neighbours, visited)) {
                return true;
            }
        }
        return false;
    }
};