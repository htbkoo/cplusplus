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
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<tuple<int, int, int>> pq;
        
        vector<vector<int>> dists;
        for (int i = 0; i < points.size(); i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < points.size(); j++) {
                int x2 = points[j][0], y2 = points[j][1];
                
                int dist = abs(x1 - x2) + abs(y1 - y2);
                
                pq.push({-dist, i, j});
            }
        }
        
        parents = vector<int>();
        for (int i = 0; i < points.size(); ++i) {
            parents.push_back(i);
        }
        
        sizes = vector<int>(points.size(), 1);
        
        int answer = 0;
        int numGroups = points.size();
        while (numGroups > 1) {
            auto [neg_dist, i, j] = pq.top();
            pq.pop();
            
            if (u(i, j) == 1) {                
                answer -= neg_dist;
                numGroups--;
            }
        }
        
        return answer;
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
    
    int u(int x, int y) {
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

int main() {
    Solution soln;
    vector<vector<int>> points = {{3,12},{-2,5},{-4,1}};

    cout << soln.minCostConnectPoints(points) << endl;

    return 0;
}