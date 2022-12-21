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
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> neighbours;
        unordered_map<int, bool> grouping;

        for (vector<int> dislike: dislikes) {
            int a = dislike[0], b = dislike[1];
            neighbours[a].push_back(b);
            neighbours[b].push_back(a);
        }

        for (int i = 1; i <= n; i++) {
            if (grouping.count(i) == 0 && !canGroup(i, true, grouping, neighbours)) {
                return false;
            }
        }

        return true;
    }

private:
    bool canGroup(
        int person,
        bool isFirstGroup,
        unordered_map<int, bool>& grouping,
        unordered_map<int, vector<int>>& neighbours
    ) {
        if (grouping.count(person) > 0) {
            return isFirstGroup == grouping[person];
        }
        grouping[person] = isFirstGroup;

        for (auto neighbour: neighbours[person]) {
            if (!canGroup(neighbour, !isFirstGroup, grouping, neighbours)) {
                return false;
            }
        }

        return true;
    }
};