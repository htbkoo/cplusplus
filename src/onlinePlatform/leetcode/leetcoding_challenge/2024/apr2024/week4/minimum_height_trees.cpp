#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <limits>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iterator>
#include <sstream>
#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> indegrees(n, 0);
        vector<unordered_set<int>> neighbours;

        unordered_set<int> remains;
        for (int i = 0; i < n; ++i) {
            neighbours.push_back(unordered_set<int>());
            remains.insert(i);
        }

        for (auto edge: edges) {
            int a = edge[0], b = edge[1];
            indegrees[a]++;
            indegrees[b]++;
            neighbours[a].insert(b);
            neighbours[b].insert(a);
        }

        deque<int> candidates;
        for (int i = 0; i < n; ++i) {
            if (indegrees[i] == 1) {
                candidates.push_back(i);
            }
        }

        while (remains.size() > 2 && candidates.size() > 0) {
            int count = candidates.size();
            for (int i = 0; i < count; ++i) {
                int node = candidates.front();
                candidates.pop_front();

                // if (remains.count(node) == 0) {
                //     continue;
                // }

                remains.erase(node);
                for (auto nextNode: neighbours[node]) {
                    indegrees[nextNode]--;
                    if (indegrees[nextNode] <= 1) {
                        if (remains.count(nextNode) > 0) {
                            candidates.push_back(nextNode);
                        }
                    }
                }
            }
        }

        // TODO: valdiate input, e.g. edges forma a tree and no repeated edges

        return vector<int>(begin(remains), end(remains));
    }
};

int main() {
    Solution soln;

    int n = 84;
    vector<vector<int>> edges = {{0,1},{1,2},{2,3},{1,4},{0,5},{0,6},{6,7},{0,8},{1,9},{7,10},{8,11},{5,12},{8,13},{13,14},{5,15},{14,16},{10,17},{13,18},{16,19},{14,20},{8,21},{8,22},{16,23},{1,24},{15,25},{11,26},{9,27},{17,28},{26,29},{27,30},{17,31},{0,32},{31,33},{33,34},{33,35},{16,36},{17,37},{0,38},{34,39},{27,40},{37,41},{38,42},{21,43},{17,44},{20,45},{17,46},{40,47},{45,48},{39,49},{11,50},{25,51},{3,52},{23,53},{47,54},{43,55},{28,56},{11,57},{52,58},{20,59},{48,60},{37,61},{11,62},{43,63},{36,64},{64,65},{53,66},{14,67},{47,68},{61,69},{25,70},{5,71},{25,72},{23,73},{51,74},{25,75},{43,76},{35,77},{38,78},{66,79},{53,80},{67,81},{6,82},{82,83}};

    auto answer = soln.findMinHeightTrees(n, edges);
/*
84
[[0,1],[1,2],[2,3],[1,4],[0,5],[0,6],[6,7],[0,8],[1,9],[7,10],[8,11],[5,12],[8,13],[13,14],[5,15],[14,16],[10,17],[13,18],[16,19],[14,20],[8,21],[8,22],[16,23],[1,24],[15,25],[11,26],[9,27],[17,28],[26,29],[27,30],[17,31],[0,32],[31,33],[33,34],[33,35],[16,36],[17,37],[0,38],[34,39],[27,40],[37,41],[38,42],[21,43],[17,44],[20,45],[17,46],[40,47],[45,48],[39,49],[11,50],[25,51],[3,52],[23,53],[47,54],[43,55],[28,56],[11,57],[52,58],[20,59],[48,60],[37,61],[11,62],[43,63],[36,64],[64,65],[53,66],[14,67],[47,68],[61,69],[25,70],[5,71],[25,72],[23,73],[51,74],[25,75],[43,76],[35,77],[38,78],[66,79],[53,80],[67,81],[6,82],[82,83]]

[0,6]
*/

    return 0;
}
