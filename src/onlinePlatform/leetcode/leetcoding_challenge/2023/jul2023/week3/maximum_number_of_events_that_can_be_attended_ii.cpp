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
    int maxValue(vector<vector<int>>& events, int k) {
        int answer = 0;
        map<int, int> bestValues;
        
        sort(events.begin(), events.end(), [](vector<int> eventA, vector<int> eventB) { return eventA[1] < eventB[1];});
        
        for (;k > 0;--k) {
            map<int, int> prevBestValues = bestValues;
            bestValues = map<int, int>();
        
            for (auto event: events) {
                int startDay = event[0], endDay = event[1], value = event[2];

                auto it = prevBestValues.lower_bound(startDay);

                int prevValue = 0;            
                if (it != prevBestValues.begin()) {
                    prevValue = prev(it)->second;
                }

                bestValues[endDay] = max(bestValues[endDay], value + prevValue);

                answer = max(answer, bestValues[endDay]);
            }    
        }
                
        return answer;
    }
};

class WASolution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int answer = 0;
        map<int, int> bestValues;
        
        sort(events.begin(), events.end(), [](vector<int> eventA, vector<int> eventB) { return eventA[1] < eventB[1];});
        
        for (auto event: events) {
            int startDay = event[0], endDay = event[1], value = event[2];
            
            auto it = bestValues.lower_bound(startDay);
            
            int prevValue = 0;            
            if (it != bestValues.begin()) {
                prevValue = prev(it)->second;
            }
            
            bestValues[endDay] = max(bestValues[endDay], value + prevValue);
                
            answer = max(answer, bestValues[endDay]);
        }
        
        return answer;
    }
};

int main() {
    Solution soln;

    // vector<vector<int>> events{{1,2,4},{3,4,3},{2,3,1}};
    // int k = 2;
    vector<vector<int>> events{{1,1,1},{2,2,2},{3,3,3},{4,4,4}};
    int k = 3;

    cout << soln.maxValue(events, k) << endl;
    
    return 0;
}