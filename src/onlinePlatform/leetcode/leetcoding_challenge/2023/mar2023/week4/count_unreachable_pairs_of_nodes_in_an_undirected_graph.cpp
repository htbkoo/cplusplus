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
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> neighbours;
        for (auto& edge: edges) {
            int a = edge[0], b = edge[1];
            neighbours[a].insert(b);
            neighbours[b].insert(a);
        }
        
        unordered_set<int> visited;
        long long answer = 0;
        
        for (int i = 0; i < n; i++) {
            int groupSize = dfs(i, neighbours, visited);
            answer += (long long) groupSize * (long long) (n - groupSize);
        }
            
        return answer / 2LL;
    }
    
private:
    int dfs(int i, unordered_map<int, unordered_set<int>>& neighbours, unordered_set<int>& visited) {
        if (visited.count(i) > 0) {
            return 0;
        }
        visited.insert(i);
        
        int groupSize = 1;
        for (int next: neighbours[i]) {
            groupSize += dfs(next, neighbours, visited);
        }
        
        return groupSize;
    }
};
