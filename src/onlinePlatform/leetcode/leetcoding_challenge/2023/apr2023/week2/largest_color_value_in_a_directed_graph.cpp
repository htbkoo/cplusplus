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
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int answer = -1;
        
        unordered_map<int, int> outCounts;
        unordered_map<int, unordered_set<int>> parentsOf;
        unordered_map<int, unordered_set<int>> neighbours;
        for (auto edge: edges) {
            int a = edge[0], b = edge[1];
            neighbours[a].insert(b);
            parentsOf[b].insert(a);
            outCounts[a]++;
        }
        
        
        int nodeCounts = colors.size();
        vector<unordered_set<int>> tsortedNodes;
        tsortedNodes.push_back(unordered_set<int>());
        for (int i = 0; i < colors.size(); i++) {
            if (outCounts[i] == 0) {
                tsortedNodes.back().insert(i);
            }
        }
        
        while (tsortedNodes.back().size() > 0) {
            unordered_set<int> candidates = tsortedNodes.back();
            tsortedNodes.push_back(unordered_set<int>());
            
            for (auto candidate: candidates) {
                nodeCounts--;
                
                for (auto parent: parentsOf[candidate]) {
                    outCounts[parent]--;
                    if (outCounts[parent] == 0) {                        
                        tsortedNodes.back().insert(parent);
                    }
                }
            }            
        }
        
        if (nodeCounts > 0) {
            return -1;
        }
                    
        unordered_map<int, unordered_map<char, int>> colorCountsByNode;
        for (auto candidates: tsortedNodes) {
            for (auto node: candidates) {                
                for (auto neighbour: neighbours[node]) {
                    for (auto& [ch, count]: colorCountsByNode[neighbour]) {
                        colorCountsByNode[node][ch] = max(colorCountsByNode[node][ch], count);
                    }
                }

                char color = colors[node];
                colorCountsByNode[node][color]++;
                
                answer = max(answer, colorCountsByNode[node][color]);
            }
        }
        
        return answer;
    }
};

class WASolution2 {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        answer = -1;
        
        unordered_map<int, int> inCounts;
        unordered_map<int, unordered_set<int>> neighbours;
        for (auto edge: edges) {
            int a = edge[0], b = edge[1];
            neighbours[a].insert(b);
            inCounts[b]++;
        }
                        
        unordered_map<char, int> colorCounts;
        unordered_set<int> visited;        
        unordered_set<int> path;        
        for (int i = 0; i < colors.size(); i++) {
            if (inCounts[i] == 0) {
                dfs(i, colors, neighbours, colorCounts, visited, path);
                if (answer == HAS_CYCLE) {
                    return -1;
                }
            }
        }
        
        return answer;
    }
    
private:
    int HAS_CYCLE = numeric_limits<int>::max();
    int answer;
    
    void dfs(
        int node,
        string& colors, 
        unordered_map<int, unordered_set<int>>& neighbours, 
        unordered_map<char, int>& colorCounts, 
        unordered_set<int>& visited,
        unordered_set<int>& path
    ) {
        if (visited.count(node) > 0) {
            return;
        }
        visited.insert(node);
        
        if (path.count(node) > 0) {
            answer = HAS_CYCLE;
            return;
        }
        path.insert(node);
        
        char color = colors[node];
        colorCounts[color]++;
        answer = max(answer, colorCounts[color]);
        for (auto neighbour: neighbours[node]) {
            dfs(neighbour, colors, neighbours, colorCounts, visited, path); 
        }        
        colorCounts[color]--;
        path.erase(node);
    }
};

class WASolution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        answer = 0;
        
        unordered_map<int, unordered_set<int>> neighbours;
        for (auto edge: edges) {
            int a = edge[0], b = edge[1];
            neighbours[a].insert(b);
        }
                
        unordered_map<char, int> colorCounts;
        unordered_set<int> visited;        
        for (int i = 0; i < colors.size(); i++) {
            if (visited.count(i) == 0) {
                dfs(i, colors, neighbours, colorCounts, visited);
                if (answer == HAS_CYCLE) {
                    return -1;
                }
            }
        }
        
        return answer;
    }
    
private:
    int HAS_CYCLE = numeric_limits<int>::max();
    int answer;
    
    void dfs(
        int node,
        string& colors, 
        unordered_map<int, unordered_set<int>>& neighbours, 
        unordered_map<char, int>& colorCounts, 
        unordered_set<int>& visited
    ) {
        if (visited.count(node) > 0) {
            answer = HAS_CYCLE;
            return;
        }
        visited.insert(node);
        
        char color = colors[node];
        colorCounts[color]++;
        answer = max(answer, colorCounts[color]);
        for (auto neighbour: neighbours[node]) {
            dfs(neighbour, colors, neighbours, colorCounts, visited); 
        }
    }
};