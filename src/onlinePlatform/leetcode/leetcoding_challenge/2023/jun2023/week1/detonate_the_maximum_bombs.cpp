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
    int maximumDetonation(vector<vector<int>>& bombs) {
        vector<unordered_set<int>> neighbours(bombs.size());
        for (int i = 0; i < bombs.size(); i++) {
            for (int j = i + 1; j < bombs.size(); j++) {
                if (isInRange(bombs[i], bombs[j])) {
                    neighbours[i].insert(j);
                }
                
                if (isInRange(bombs[j], bombs[i])) {
                    neighbours[j].insert(i);
                }
            }
        }
        
        // for all bombs, find number of bombs it can detonate and record the max
        int answer = 0;
        for (int i = 0; i < bombs.size(); i++) {
            unordered_set<int> visited;
            answer = max(
                answer,
                findNumBombsDetonated(neighbours, visited, i)
            );
        }
        
        return answer;
    }
    
private:
    bool isInRange(vector<int> bomb, vector<int> target) {
        long x1 = bomb[0], y1 = bomb[1], r1 = bomb[2];
        long x2 = target[0], y2 = target[1];
        
        long dx = abs(x1 - x2), dy = abs(y1 - y2);
        
        return (r1*r1) >= ((dx*dx) + (dy * dy));
    }
    
    int findNumBombsDetonated(vector<unordered_set<int>>& neighbours, unordered_set<int>& visited, int i) {
        if (visited.count(i) > 0) {
            return 0;
        }
        visited.insert(i);
                
        int count = 1; // bomb[i]
        for (int nextBomb: neighbours[i]) {
            count += findNumBombsDetonated(neighbours, visited, nextBomb);
        }
        return count;
    }
};