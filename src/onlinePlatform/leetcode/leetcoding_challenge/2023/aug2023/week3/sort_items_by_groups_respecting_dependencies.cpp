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
        for (int i = 0; i < m; ++i) {
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
            int firstItem = *items.begin();
            for (auto item: items) {
                numGroups -= unionGroups(firstItem, item);
            }
        }
        
        vector<unordered_set<int>> itemsInGroups;
        for (int i = 0; i < m; ++i) {
            itemsInGroups.push_back(unordered_set<int>());
        }        
        for (int i = 0; i < n; ++i) {
            int itemGroup = find(i);
            itemsInGroups[itemGroup].insert(i);
        }
        
        // sortGroup
        vector<unordered_set<int>> groupsAfter;
        vector<unordered_set<int>> groupsBefore;
        for (int after = 0; after < beforeItems.size(); ++after) {
            int a = find(after);
            for (int before: beforeItems[after]) {                
                int b = find(before);
                groupsAfter[b].insert(a);
                groupsBefore[a].insert(b);
            }
        }
        queue<int> candidates;
        vector<int> outdegrees;
        for (auto& g: groupsBefore) {
            if (g.size() == 0) {
                candidates.push(outdegrees.size());
            }
            outdegrees.push_back(g.size());
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
};