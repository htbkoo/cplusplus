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
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        int START = 0;
        int END = n - 1;
        
        vector<vector<int>> answer;
        dfs(graph, START, END, {}, answer);
        
        return answer;
    }
    
private:
    void dfs(
        vector<vector<int>>& graph, 
        int node, 
        int END, 
        vector<int> path,
        vector<vector<int>>& answer
    ) {
        path.push_back(node);
        if (node == END) {
            answer.push_back(path);
            return;
        }        
        for (int nextNode: graph[node]) {
            dfs(graph, nextNode, END, path, answer);
        }
    }
};