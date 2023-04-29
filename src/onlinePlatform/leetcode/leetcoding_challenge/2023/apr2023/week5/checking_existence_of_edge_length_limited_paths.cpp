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
#include <cstring> // for memset
using namespace std; // since cin and cout are both in namespace std, this saves some text

const int MAX_NUM_NODES = 1e5;

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        for (int i = 0; i < n; ++i) {
            parents[i] = i;
        }
        
        // TODO: assume we can mutae queries
        for (int q = 0; q < queries.size(); ++q) {
            queries[q].push_back(q);
        }
        sort(queries.begin(), queries.end(), [](vector<int>& queryA, vector<int>& queryB){return queryA[2] < queryB[2];});
        
        sort(edgeList.begin(), edgeList.end(), [](vector<int>& edgeA, vector<int>& edgeB){return edgeA[2] < edgeB[2];});
        
        int e = 0;
        
        vector<bool> answers(queries.size(), false);        
        for (auto query: queries) {
            int p = query[0], q = query[1], limit = query[2], idx = query[3];
            
            while (e < edgeList.size()) {
                auto edge = edgeList[e];
                int u = edge[0], v = edge[1], dis = edge[2];                
                if (dis >= limit) {
                    break;
                }
                
                unionSet(u, v);
                
                e++;
            }
            
            answers[idx] = find(p) == find(q);
        }        
        return answers;
    }
    
private:
    int parents[MAX_NUM_NODES + 1];
    
    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }
    
    void unionSet(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        parents[y] = x;
    }
};