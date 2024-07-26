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
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int UNREACHABLE = numeric_limits<int>::max();
        
        vector<vector<int>> dists(n, vector<int>(n, UNREACHABLE));
        for (int i = 0; i < n; ++i) {
            dists[i][i] = 0;
        }
        
        for (auto &edge: edges) {
            int fromCity = edge[0];
            int toCity = edge[1];
            int weight = edge[2];
            
            dists[fromCity][toCity] = min(dists[fromCity][toCity], weight);
            dists[toCity][fromCity] = min(dists[toCity][fromCity], weight);
        }
        
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dists[i][k] < UNREACHABLE && dists[k][j] < UNREACHABLE) {
                        dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
                    }
                }
            }
        } 
        
        int minNumNeighbours = n;
        int answer = n - 1;
        for (int i = n - 1; i >= 0; --i) {
            int numReachable = 0;
            for (int j = 0; j < n; ++j) {
                if (dists[i][j] <= distanceThreshold) {
                    numReachable++;
                }
            }

            if (numReachable < minNumNeighbours) {
                minNumNeighbours = numReachable;
                answer = i;
            }
        }
        
        return answer;
    }
};
