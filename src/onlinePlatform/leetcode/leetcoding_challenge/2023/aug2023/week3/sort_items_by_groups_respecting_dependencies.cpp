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

const int NO_GROUP = -1;
const vector<int> NO_SOLUTION = {};


class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        parents = vector<int>();
        for (int i = 0; i < n; ++i) {
            parents.push_back(i);
        }        
        sizes = vector<int>(n, 1);
        
        vector<unordered_set<int>> groupMap;
        for (int i = 0; i < n; ++i) {
            groupMap.push_back(unordered_set<int>());
        }        
        for (int i = 0; i < n; ++i) {
            if (NO_GROUP != group[i]) {
                groupMap[group[i]].insert(i);
            }
        }
        
        int numGroups = n;
        for (int i = 0; i < groupMap.size(); ++i) {
            auto items = groupMap[i];
            if (items.size() == 0) {
                continue;
            }
            int firstItem = *items.begin();
            for (auto item: items) {
                numGroups -= unionGroups(firstItem, item);
            }
        }
        
        vector<unordered_set<int>> itemsInGroups;
        for (int i = 0; i < n; ++i) {
            itemsInGroups.push_back(unordered_set<int>());
        }        
        for (int i = 0; i < n; ++i) {
            int itemGroup = find(i);
            itemsInGroups[itemGroup].insert(i);
        }
        
        // sortGroup
        unordered_map<int, unordered_set<int>> groupsAfter;
        unordered_map<int, int> outdegrees;
        for (int after = 0; after < beforeItems.size(); ++after) {
            int a = find(after);
            if (outdegrees.count(a) == 0) {
                outdegrees[a] = 0;
            }
            for (int before: beforeItems[after]) {                
                int b = find(before);
                if (a != b) {
                    groupsAfter[b].insert(a);
                    outdegrees[a]++;
                }
            }
        }
        queue<int> candidates;
        for (auto& [i, outdegree]: outdegrees) {
            if (outdegree == 0) {
                candidates.push(i);
            }
        }
        vector<int> orderedGroups;
        while (candidates.size() > 0) {
            auto c = candidates.front();
            candidates.pop();
            orderedGroups.push_back(c);
            
            for (auto nextGroup: groupsAfter[c]) {
                outdegrees[nextGroup]--;
                if (outdegrees[nextGroup] == 0) {
                    candidates.push(nextGroup);
                } 
            }
        }

        if (orderedGroups.size() < numGroups) {
            return NO_SOLUTION;
        }
        
        vector<int> answer;
        // sortItemsInGroup
        for (auto g: orderedGroups) {
            if (!expandGroupAndSort(answer, g, itemsInGroups, beforeItems)) {
                // there are cycle within the group
                return NO_SOLUTION;
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
    
    int unionGroups(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return 0;
        }
        
        if (sizes[y] > sizes[x]) {
            int temp = y;
            y = x;
            x = temp;
        }
        parents[y] = x;
        sizes[x] += sizes[y];
        return 1;
    }

    bool expandGroupAndSort(
        vector<int>& answer, 
        int g, 
        vector<unordered_set<int>>& itemsInGroups, 
        vector<vector<int>>& beforeItems
    ) {
        auto& items = itemsInGroups[g];

        unordered_map<int, int> outdegrees;
        unordered_map<int, unordered_set<int>> itemsAfter;
        for (auto item: items) {
            outdegrees[item] = 0;
            itemsAfter[item] = unordered_set<int>();
        }
        for (auto item: items) {
            for (auto before: beforeItems[item]) {
                bool isInSameGroup = items.count(before) > 0;
                if (isInSameGroup) {
                    outdegrees[item]++;
                    itemsAfter[before].insert(item);
                } 
            }
        }

        queue<int> candidates;
        for (auto& [item, outdegree]: outdegrees) {
            if (outdegree == 0) {
                candidates.push(item);
            }
        }

        vector<int> result;
        while (candidates.size() > 0) {
            int c = candidates.front();
            candidates.pop();

            result.push_back(c);
            for (auto after: itemsAfter[c]) {
                outdegrees[after]--;
                if (outdegrees[after] == 0) {
                    candidates.push(after);
                }
            }
        }

        if (result.size() < items.size()) {
            return false;
        }

        for (auto item: result) {
            answer.push_back(item);
        }

        return true;
    }
};

int main() {
    Solution soln;

    int n = 8, m = 2;
    vector<int> group = {-1,-1,1,0,0,1,0,-1};
    vector<vector<int>> beforeItems = {{},{6},{5},{6},{3,6},{},{},{}};

    for (auto i: soln.sortItems(n, m, group, beforeItems)) {
        cout << i << ", ";
    }

    cout << endl;

    return 0;
}