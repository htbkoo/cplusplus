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

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        const int EDGE_TYPE_BOTH = 3;
        const int NOT_FULLY_TRAVERSABLE = -1;
        
        vector<int> parents = {-1};
        vector<int> sizes = {-1};
        for (int i = 1; i <= n; ++i) {
            parents.push_back(i);
            sizes.push_back(1);
        }
                        
        vector<vector<pair<int, int>>> edgesByType = {{}, {}, {}, {}};
        for (auto edge: edges) {
            int type = edge[0], u = edge[1], v = edge[2];
            edgesByType[type].push_back(pair{u, v});
        }
        
        int answer = 0;

        answer += countNumRemovableEdgesAndUpdateDisjointSet(parents, sizes, edgesByType[EDGE_TYPE_BOTH]);
        
        for (int edgeType = 1; edgeType <= 2; edgeType++) {
            vector<int> tempParents(parents.begin(), parents.end());
            vector<int> tempSizes(sizes.begin(), sizes.end());
            answer += countNumRemovableEdgesAndUpdateDisjointSet(tempParents, tempSizes, edgesByType[edgeType]);
            if (!isFullyTraversable(tempParents)) {
                return NOT_FULLY_TRAVERSABLE;
            }
        }
        
        return answer;
    }
    
private:
    int find(vector<int>& parents, int x) {
        if (parents[x] != x) {
            parents[x] = find(parents, parents[x]);
        }
        return parents[x];
    }
    
    bool unionSet(vector<int>& parents, vector<int>& sizes, int x, int y) {
        x = find(parents, x);
        y = find(parents, y);
        
        if (x == y) {
            return false;
        }
        
        if (sizes[y] > sizes[x]) {
            int temp = x;
            x = y;
            y = temp;
        }
        
        parents[y] = x;
        sizes[x] += sizes[y];
        return true;
    }
    
    int countNumRemovableEdgesAndUpdateDisjointSet(vector<int>& parents, vector<int>& sizes, vector<pair<int, int>>& edges) {
        int count = 0;
        for (auto& [u, v]: edges) {
            if (!unionSet(parents, sizes, u, v)) {
                count++;
            }
        }
        return count;
    }
    
    bool isFullyTraversable(vector<int>& parents) {
        unordered_set<int> s;
        
        for (int i = 1; i < parents.size(); i++) {
            s.insert(parents[i]);
        }
        
        return s.size() == 1;
    }
};

class WIPSolution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> parents = {-1};
        for (int i = 1; i <= n; ++i) {
            parents.push_back(i);
        }
        
        int countDuplicatedEdges = 0;
                
        unordered_map<int, unordered_map<int, unordered_set<int>>> neighboursByType;
        
        for (auto edge: edges) {
            int type = edge[0], u = edge[1], v = edge[2];
            bool isDuplicated = neighboursByType.count(type) > 0 && neighboursByType[type].count(u) > 0 && neighboursByType[type][u].count(v) > 0;
            if (isDuplicated) {
                countDuplicatedEdges++;
            } else {
                neighboursByType[type][u].insert(v);
                neighboursByType[type][v].insert(u);
            }
        }
        
        return -1;
    }
};

template <typename V>
void printVector(V v) {
    cout << "[";
    for (auto item: v) {
        cout << item << ", ";
    }
    cout << "]";
    cout << endl;
}

int main() {
    Solution soln;
    int n = 4;
    vector<vector<int>> edges = {{3,1,2},{3,2,3},{1,1,3},{1,2,4},{1,1,2},{2,3,4}};

    cout << soln.maxNumEdgesToRemove(n, edges) << endl;

    return 0;
}