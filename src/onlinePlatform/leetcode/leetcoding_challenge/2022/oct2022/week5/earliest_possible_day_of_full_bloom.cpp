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
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<int> indices;
        for (int i = 0; i < plantTime.size(); i++) {
            indices.push_back(i);
        }
        
        sort(indices.begin(), indices.end(), [&growTime](int a, int b) {
            return growTime[a] > growTime[b];
        });
        
        int totalPlantTimes = 0;
        int answer = 0;
        
        for (int i = 0; i < indices.size(); i++) {
            int index = indices[i];
            totalPlantTimes += plantTime[index];
            answer = max(answer, totalPlantTimes + growTime[index]);
        }
        
        return answer;
    }
};

class WASolution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int totalPlantTimes = 0;
        int shortestGrowTime = growTime[0];
        
        for (int i = 0; i < plantTime.size(); i++) {
            totalPlantTimes += plantTime[i];
            shortestGrowTime = min(shortestGrowTime, growTime[i]);
        }
        
        return totalPlantTimes + shortestGrowTime;
    }
};