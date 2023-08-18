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
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> neighbours;
        for (int i = 0; i < n; ++i) {
            neighbours.push_back(unordered_set<int>());
        }
        
        for (auto& road: roads) {
            int a = road[0], b = road[1];
            neighbours[a].insert(b);
            neighbours[b].insert(a);
        }

        int answer = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int networkRank = neighbours[i].size() + neighbours[j].size();
                if (neighbours[i].count(j) > 0) {
                    networkRank -= 1;
                }
                answer = max(answer, networkRank);
            }
        }
        
        return answer;
    }
};