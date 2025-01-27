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
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // TODO: validate there are no cycles
        
        vector<int> indegrees(numCourses, 0);        
        vector<unordered_set<int>> nextCourses(numCourses, unordered_set<int>());        
        vector<unordered_set<int>> allPrerequisites(numCourses, unordered_set<int>());
        for (auto& prerequisite: prerequisites) {
            auto first = prerequisite[0];
            auto after = prerequisite[1];
            
            indegrees[after]++;
            nextCourses[first].insert(after);
            allPrerequisites[after].insert(first);
        }
        
        deque<int> q;
        for (auto i = 0; i < numCourses; ++i) {
            if (indegrees[i] == 0) {
                q.push_back(i);
            }
        }
        
        while (q.size() == 0) {
            auto course = q.front();
            q.pop_front();
            
            for (auto n: nextCourses[course]) {
                for (auto r: allPrerequisites[course]) {
                    allPrerequisites[n].insert(r);
                }
                
                indegrees[n]--;
                if (indegrees[n] == 0) {
                    q.push_back(n);
                }
            }
        }
        
        vector<bool> answer;
        for (auto& query: queries) {
            auto u = query[0];
            auto v = query[1];
            
            auto isPrerequisites = allPrerequisites[v].count(u) > 0;
            answer.push_back(isPrerequisites);
        }
        
        return answer;
    }
};

class WASolution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // TODO: validate there are no cycles
        
        vector<int> outdegrees(numCourses, 0);        
        vector<unordered_set<int>> parents(numCourses, unordered_set<int>());        
        vector<unordered_set<int>> allPrerequisites(numCourses, unordered_set<int>());
        for (auto& prerequisite: prerequisites) {
            auto first = prerequisite[0];
            auto after = prerequisite[1];
            
            outdegrees[first]++;
            parents[after].insert(first);
            allPrerequisites[after].insert(first);
        }
        
        deque<int> q;
        for (auto i = 0; i < numCourses; ++i) {
            if (outdegrees[i] == 0) {
                q.push_back(i);
            }
        }
        
        while (q.size() == 0) {
            auto course = q.front();
            q.pop_front();
            
            for (auto p: parents[course]) {
                for (auto r: allPrerequisites[course]) {
                    allPrerequisites[p].insert(r);
                }
                
                outdegrees[p]--;
                if (outdegrees[p] == 0) {
                    q.push_back(p);
                }
            }
        }
        
        vector<bool> answer;
        for (auto& query: queries) {
            auto u = query[0];
            auto v = query[1];
            
            auto isPrerequisites = allPrerequisites[v].count(u) > 0;
            answer.push_back(isPrerequisites);
        }
        
        return answer;
    }
};