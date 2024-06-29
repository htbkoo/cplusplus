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
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> children(n, vector<int>());
        vector<int> indegrees(n);
        
        for (auto edge: edges) {
            auto fromNode = edge[0];
            auto toNode = edge[1];
            
            children[fromNode].push_back(toNode);
            indegrees[toNode]++;
        }
        
        vector<set<int>> ancestors(n, set<int>());
        
        deque<int> candidates;
        for (int i = 0; i < n; ++i) {
            if (indegrees[i] == 0) {
                candidates.push_back(i);
            }
        }
        
        while (candidates.size() > 0) {
            auto node = candidates.front();
            candidates.pop_front();
            
            for (auto child: children[node]) {
                for (auto toAdd: ancestors[node]) {
                    ancestors[child].insert(toAdd);
                }
                ancestors[child].insert(node);
                
                indegrees[child]--;
                if (indegrees[child] == 0) {
                    candidates.push_back(child);
                }
            }
        }
        
        vector<vector<int>> answer;
        for (int i = 0; i < n; ++i) {
            answer.push_back(vector<int>(begin(ancestors[i]), end(ancestors[i])));
        }
        
        return answer;
    }
};

class WASolution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> children(n, vector<int>());
        vector<int> indegrees(n);
        
        for (auto edge: edges) {
            auto fromNode = edge[0];
            auto toNode = edge[1];
            
            children[fromNode].push_back(toNode);
            indegrees[toNode]++;
        }
        
        vector<vector<int>> answer(n, vector<int>());
        
        deque<int> candidates;
        for (int i = 0; i < n; ++i) {
            if (indegrees[i] == 0) {
                candidates.push_back(i);
            }
        }
        
        while (candidates.size() > 0) {
            auto node = candidates.front();
            candidates.pop_front();
            
            for (auto child: children[node]) {
                for (auto toAdd: answer[node]) {
                    answer[child].push_back(toAdd);
                }
                answer[child].push_back(node);
                
                indegrees[child]--;
                if (indegrees[child] == 0) {
                    candidates.push_back(child);
                }
            }
        }
        
        return answer;
    }
};
