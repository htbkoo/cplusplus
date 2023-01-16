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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> answer;
        
        bool added = false;
        int currStart = newInterval[0];
        int currEnd = newInterval[1];
        for (auto interval: intervals) {
            int start = interval[0], end = interval[1];
            
            bool hasOverlap = !(end < currStart || start>currEnd);
            if (hasOverlap) {
                currStart = min(currStart, start);
                currEnd = max(currEnd, end);
            } else {
                if (!added && currEnd < start) {
                    added = true;
                    answer.push_back({currStart, currEnd});
                }
                answer.push_back(interval);
            }
        }

        if (!added) {
            answer.push_back({currStart, currEnd});
        }

        return answer;
    }
};

class WASolution2 {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> answer;
        
        int currStart = newInterval[0];
        int currEnd = newInterval[1];
        for (auto interval: intervals) {
            int start = interval[0], end = interval[1];
            if (end < newInterval[0]) {
                answer.push_back(interval);                
            } else if (start > currEnd) { 
                answer.push_back({currStart, currEnd});
                currEnd = numeric_limits<int>::max();
                answer.push_back(interval);
            } else {
                currStart = min(currStart, start);
                currEnd = max(currEnd, end);
            }
        }
        
        return answer;
    }
};

class WASolution1 {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> answer;
        
        int currStart = newInterval[0];
        int currEnd = newInterval[1];
        for (auto interval: intervals) {
            int start = interval[0], end = interval[1];
            if (end < newInterval[0]) {
                answer.push_back(interval);                
            } else if (start > currEnd) { 
                answer.push_back({currStart, currEnd});                
                currEnd = numeric_limits<int>::max();
            } else {
                currStart = min(currStart, start);
                currEnd = max(currEnd, end);
            }
        }
        
        return answer;
    }
};