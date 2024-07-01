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
    int earliestAcq(vector<vector<int>>& logs, int n) {
        if (n <= 1) {
            // TODO: confirm this
            return 0;
        }
        
        parents = vector<int>();
        sizes = vector<int> (n, 1);        
        for (int i = 0; i < n; ++i) {
            parents.push_back(i);
        }

        sort(begin(logs), end(logs));
        
        int numGroups = n;
        for (auto& log: logs) {
            auto timestamp = log[0];
            auto x = log[1];
            auto y = log[2];
            
            numGroups -= unionSets(x, y);
            if (numGroups == 1) {
                return timestamp;
            }
        }
        
        return -1;
    }
    
private:
    vector<int> parents;
    vector<int> sizes;
        
    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }
    
    int unionSets(int x, int y) {
        x = find(x);
        y = find(y);
        
        if (x == y) {
            return 0;
        }
        
        if (sizes[y] > sizes[x]) {
            int temp = x;
            x = y;
            y = temp;
        }
        
        parents[y] = x;
        sizes[x] += sizes[y];
        
        return 1;
    }
};
