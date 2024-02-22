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
    int treeDiameter(vector<vector<int>>& edges) {
        // TODO: is the tree connected? or is it a forest?

        answer = 0;

        unordered_map<int, unordered_set<int>> neighbours;
        for (auto& edge: edges) {
            int a = edge[0];
            int b = edge[1];

            neighbours[a].insert(b);
            neighbours[b].insert(a);
        }

        int ARBITRARY_ROOT = 0;
        int NO_PARENT = -1;

        dfs(ARBITRARY_ROOT, NO_PARENT, neighbours);

        return answer;
    }

private:
    int answer;

    int dfs(int node, int parent, unordered_map<int, unordered_set<int>>& neighbours) {
        int longest = 0;
        int second = 0;

        for (auto nextNode: neighbours[node]) {
            if (nextNode == parent) {
                continue;
            }
            int length = 1 + dfs(nextNode, node, neighbours);
            if (length >= longest) {
                second = longest;
                longest = length;
            } else if (length >= second) {
                second = length;
            }
        }

        answer = max(answer, longest + second);

        return longest;
    }
};
