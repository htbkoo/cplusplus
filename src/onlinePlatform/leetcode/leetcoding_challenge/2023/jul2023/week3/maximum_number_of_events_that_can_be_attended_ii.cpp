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
                
                auto itlow=bestValues.lower_bound(endDay);
                if(itlow != bestValues.begin()) {
                    itlow--;
                    bestValues[endDay] = max(bestValues[endDay], itlow->second);
                }

                answer = max(answer, bestValues[endDay]);
            }    
        }
                
        return answer;
    }
};

class WIPSolution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int answer = 0;
        vector<int> bestValues(events.size(), 0);
        
        sort(events.begin(), events.end(), [](vector<int> eventA, vector<int> eventB) { return eventA[1] < eventB[1];});
        
        for (;k > 0;--k) {
            vector<int> prevBestValues = bestValues;
            bestValues = vector<int>(events.size() + 1, 0);
            
            for (int i = 0; i < events.size(); ++i) {
                auto event = events[i];
                int startDay = event[0], endDay = event[1], value = event[2];

                int prevValue = 0;            
                if (i > 0) {
                    prevValue = prevBestValues[i - 1];
                }

                bestValues[endDay] = max(bestValues[endDay], value + prevValue);

                answer = max(answer, bestValues[endDay]);
            }    
        }
                
        return answer;
    }
};


class WASolution3 {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int answer = 0;
        vector<map<int, int>> bestValues;
        for (int i = 0; i <= k; ++i) {
            bestValues.push_back(map<int, int>());
        }
        
        sort(events.begin(), events.end(), [](vector<int> eventA, vector<int> eventB) { return eventA[1] < eventB[1];});

        for (auto event: events) {
            int startDay = event[0], endDay = event[1], value = event[2];
            for (int i = k - 1; i >= 0 ; --i) {
                map<int, int> prevBestValues = bestValues[i + 1];
                auto it = prevBestValues.lower_bound(startDay);

                int prevValue = 0;            
                if (it != prevBestValues.begin()) {
                    prevValue = prev(it)->second;
                }

                bestValues[i][endDay] = max(bestValues[i][endDay], value + prevValue);

                answer = max(answer, bestValues[i][endDay]);
            }
        }    
                
        return answer;
    }
};

class WASolution2 {
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

                cout << k << " " << startDay << " " << endDay << " " << value << ": " << prevValue << endl;
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
                cout << it->first << " " << it->second << endl;
                prevValue = prev(it)->second;
            }

            cout << startDay << " " << endDay << " " << value << ": " << prevValue << endl;

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
    // vector<vector<int>> events{{1,1,1},{2,2,2},{3,3,3},{4,4,4}};
    // int k = 3;
    vector<vector<int>> events{{19,42,7},{41,73,15},{52,73,84},{84,92,96},{6,64,50},{12,56,27},{22,74,44},{38,85,61}};
    int k = 5;

    cout << soln.maxValue(events, k) << endl;
    
    return 0;
}