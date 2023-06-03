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

const int UNINITIALIZED = -1;

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        memo = vector<int>(n, UNINITIALIZED);
        
        int answer = 0;
        for (int i = 0; i < n; ++i) {
            answer = max(answer, find(i, headID, manager, informTime));
        }
        return answer;
    }
    
private:
    vector<int> memo;
    
    int find(int i, int headID, vector<int>& manager, vector<int>& informTime) {
        if (i == headID) {
            return 0;
        }
        if (memo[i] == UNINITIALIZED) {
            int m = manager[i];
            memo[i] = informTime[m] + find(m, headID, manager, informTime);
        }
        
        return memo[i];
    }
};

class FirstSolution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<unordered_set<int>> subordinates = vector<unordered_set<int>>(manager.size());
        for (int i = 0; i < manager.size(); ++i) {
            if (i == headID) {
                continue;
            }
            int m = manager[i];
            subordinates[m].insert(i);
        }
        
        int answer = 0;
        vector<int> time = vector<int>(manager.size(), numeric_limits<int>::max());
        
        queue<int> candidates({headID});
        time[headID] = 0;
        
        while (candidates.size() > 0) {
            int c = candidates.front();
            candidates.pop();
            
            for (auto s: subordinates[c]) {
                int newTime = time[c] + informTime[c];
                time[s] = min(time[s], newTime);
                candidates.push(s);
            }
        }
            
        return *max_element(time.begin(), time.end());
    }
};

class PQSolution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<unordered_set<int>> subordinates = vector<unordered_set<int>>(manager.size());
        for (int i = 0; i < manager.size(); ++i) {
            if (i == headID) {
                continue;
            }
            int m = manager[i];
            subordinates[m].insert(i);
        }
        
        int answer = 0;
        vector<int> time = vector<int>(manager.size(), numeric_limits<int>::max());
        
        auto cmp = [&](int a, int b) { return time[a] < time[b]; };
        
        unordered_set<int> visited;
        
        vector<int> candidates{headID};
        time[headID] = 0; 
        
        while (candidates.size() > 0) {
            pop_heap(candidates.begin(), candidates.end(), cmp);
            int c = candidates.back();
            candidates.pop_back();
            
            if (visited.count(c) > 0) {
                continue;
            } 
            visited.insert(c);
            
            for (auto s: subordinates[c]) {
                int newTime = time[c] + informTime[c];
                if (newTime < time[s]) {
                    time[s] = newTime;
                    
                    candidates.push_back(s);
                    push_heap(candidates.begin(), candidates.end(), cmp);
                }
            }
        }
            
        return *max_element(time.begin(), time.end());
    }
};