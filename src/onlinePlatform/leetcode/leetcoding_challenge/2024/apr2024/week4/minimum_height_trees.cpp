#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <limits>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iterator>
#include <sstream>
#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> indegrees(n, 0);
        vector<unordered_set<int>> neighbours;
        
        unordered_set<int> remains;
        for (int i = 0; i < n; ++i) {
            neighbours.push_back(unordered_set<int>());
            remains.insert(i);
        }
        
        for (auto edge: edges) {
            int a = edge[0], b = edge[1];
            indegrees[a]++;
            indegrees[b]++;
            neighbours[a].insert(b);
            neighbours[b].insert(a);
        }
        
        deque<int> candidates;        
        for (int i = 0; i < n; ++i) {
            if (indegrees[i] == 1) {
                candidates.push_back(i);
            }
        }
        
        while (remains.size() > 2 && candidates.size() > 0) {
            int count = candidates.size();
            for (int i = 0; i < count; ++i) {
                int node = candidates.front();
                candidates.pop_front();
                    
                remains.erase(node);
                for (auto nextNode: neighbours[node]) {
                    indegrees[nextNode]--;
                    if (indegrees[nextNode] <= 1) {
                        candidates.push_back(nextNode);
                    }
                }
            }
        }
        
        // TODO: valdiate input, e.g. edges forma a tree and no repeated edges
        
        return vector<int>(begin(remains), end(remains));
    }
};
