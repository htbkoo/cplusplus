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
    int longestCycle(vector<int>& edges) {
        int answer = -1;
        unordered_set<int> visited = unordered_set<int>();
        
        for (int i = 0; i < edges.size(); i++) {
            unordered_set<int> curr;
            if (visited.count(i) == 0) {
                auto [_, cycleSize] = dfs(i, edges, curr, visited);
                answer = max(answer, cycleSize);
            }            
        }
        
        return answer;
    }
    
private:
    pair<int, int> dfs(int i, vector<int>& edges, unordered_set<int>& curr, unordered_set<int>& visited) {
        int NO_CYCLE = -1;        
        if (curr.count(i) > 0) {
            return pair{i, 0};
        }
        curr.insert(i);
        
        if (visited.count(i) > 0) {
            return pair{NO_CYCLE, NO_CYCLE};
        }
        visited.insert(i);
                        
        int next = edges[i];
        if (next == -1) {
            return pair{NO_CYCLE, NO_CYCLE};
        }
        
        auto [cycleStart, cycleSize] = dfs(next, edges, curr, visited);
        if (cycleStart == NO_CYCLE) {
            return pair{cycleStart, cycleSize};
        } else {
            if (cycleStart == i) {                
                return pair{NO_CYCLE, cycleSize + 1};
            } else {                
                return pair{cycleStart, cycleSize + 1};
            }
        }
    }
};
