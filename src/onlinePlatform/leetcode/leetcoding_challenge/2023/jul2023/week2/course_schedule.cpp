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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegrees(numCourses, 0);
        
        vector<unordered_set<int>> children;
        for (int i = 0; i < numCourses; ++i) {
            children.push_back(unordered_set<int>());
        }
        
        for (auto& prerequisite: prerequisites) {
            int child = prerequisite[0], parent = prerequisite[1];
            inDegrees[child]++;
            children[parent].insert(child);
        }
        
        int numCanTake = 0;
        
        deque<int> candidates;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegrees[i] == 0) {
                candidates.push_back(i);
            }
        }
        
        while (candidates.size() > 0) {
            int count = candidates.size();
            for (int i = 0; i < count; ++i) {
                int candidate = candidates.front();
                candidates.pop_front();
                
                numCanTake++;
                
                for (auto child: children[candidate]) {
                    inDegrees[child]--;
                    if (inDegrees[child] == 0) {
                        candidates.push_back(child);
                    }
                }
            }
        }
        
        return numCanTake == numCourses;
    }
};
