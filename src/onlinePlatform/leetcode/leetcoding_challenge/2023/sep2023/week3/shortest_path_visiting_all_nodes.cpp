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
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        
        int BITMASK_ALL_VISITED = (1 << n) - 1;
        
        visited = set<pair<int, int>>();
        
        deque<pair<int, int>> dq; 
        for (int i = 0; i < n; ++i) {
            dq.push_back(pair{i, withNode(0, i)});
        }
        
        int steps = 0;
        while (dq.size() > 0) {
            int count = dq.size();
            for (int i = 0; i < count; ++i) {
                auto [node, bitmask] = dq.front();
                dq.pop_front();
                
                if (bitmask == BITMASK_ALL_VISITED) {
                    return steps;
                }
                
                pair<int, int> state = pair{node, bitmask};
                if (visited.count(state) > 0) {
                    continue;
                }
                visited.insert(state);
                
                for (auto nextNode: graph[node]) {
                    pair<int, int> newState = pair{nextNode, withNode(bitmask, nextNode)};
                    dq.push_back(newState);
                }
            }
            steps++;
        }
        
        // TODO: throw error instead
        return -1;
    }
    
private:
    set<pair<int, int>> visited;
    int withNode(int bitmask, int i) {
        return bitmask | 1 << i;
    }    
};