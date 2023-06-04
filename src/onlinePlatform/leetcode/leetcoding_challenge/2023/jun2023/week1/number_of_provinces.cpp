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
    int findCircleNum(vector<vector<int>>& isConnected) {
        const int UNINITIALIZED = -1;
        
        int numProvinces = 0;
        // vector<int> provinces(isConnected.size(), UNINITIALIZED);
        vector<bool> visited(isConnected.size(), false);
        
        for (int i = 0; i < isConnected.size(); ++i) {
            if (!visited[i]) {
                numProvinces++;
                dfs(isConnected, visited, i);
            }
        }
        
        return numProvinces;
    }
    
private:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int i) {
        if (visited[i]) {
            return;
        }
        visited[i] = true;
        
        for (int j = 0; j < isConnected.size(); ++j) {
            if (i != j && isConnected[i][j]) {
                dfs(isConnected, visited, j);
            }
        }
    }
};