#include <algorithm>
#include <cmath>
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
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<int> indices;
        for (int i = 0; i < startTime.size(); i++) {
            indices.push_back(i);
        }
        
        sort(indices.begin(), indices.end(), [&](int a, int b) { return endTime[a] < endTime[b]; });
        
        int answer = 0;
        map<int, int> bestProfits;
        for (int idx: indices) {
            int s = startTime[idx], e = endTime[idx], p = profit[idx];
            
            int prevP = 0;
            auto it = bestProfits.upper_bound(s);
            if (it != bestProfits.begin()) {
                auto& [_, temp] = *prev(it);
                prevP = temp;
            }
            if (bestProfits.count(e) == 0) {
                bestProfits[e] = 0;
            }
            bestProfits[e] = max({bestProfits[e], p + prevP, answer});

            answer = max(answer, bestProfits[e]);
        }
        
        return answer;
    }
};

class WIPSolution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<int> indices;
        for (int i = 0; i < startTime.size(); i++) {
            indices.push_back(i);
        }
        
        sort(indices.begin(), indices.end(), [&](int a, int b) { return startTime[a] < startTime[b]; });
        
        int answer = 0;
        vector<int> bestProfits = vector<int>(indices.size());

        // upper_bound(indices.begin(), indices.end(), [&](int a, int b) {
        //     return  <
        // });
        for (int idx: indices) {
            int s = startTime[idx], e = endTime[idx], p = profit[idx];
            
            // auto it = bestProfits.lower_bound(s);
            // auto it = bestProfits.upper_bound(s);
            // if (it != bestProfits.begin()) {
            //     auto& [_, prevP] = *prev(it);
            //     p += prevP;
            // }
            // if (bestProfits.count(e) == 0) {
            //     bestProfits[e] = 0;
            // }
            // bestProfits[e] = max(bestProfits[e], p);

            answer = max(answer, bestProfits[e]);
        }
        
        return answer;
    }
};

class WASolution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<int> indices;
        for (int i = 0; i < startTime.size(); i++) {
            indices.push_back(i);
        }
        
        sort(indices.begin(), indices.end(), [&](int a, int b) { return startTime[a] < startTime[b]; });
        
        int answer = 0;
        map<int, int> bestProfits;
        for (int idx: indices) {
            int s = startTime[idx], e = endTime[idx], p = profit[idx];
            
            // auto it = bestProfits.lower_bound(s);
            auto it = bestProfits.upper_bound(s);
            if (it != bestProfits.begin()) {
                auto& [_, prevP] = *prev(it);
                p += prevP;
            }
            if (bestProfits.count(e) == 0) {
                bestProfits[e] = 0;
            }
            bestProfits[e] = max(bestProfits[e], p);

            answer = max(answer, bestProfits[e]);
        }
        
        return answer;
    }
};

int main() {
    Solution soln;
    
    // vector<int> startTime = {1,2,3,3}, endTime = {3,4,5,6}, profit = {50,10,40,70};
    // vector<int> startTime = {1,2,3,4,6}, endTime = {3,5,10,6,9}, profit = {20,20,100,70,60};
    // vector<int> startTime = {2,1,6,3,4}, endTime = {3,5,10,6,9}, profit = {20,20,100,70,60};
    
    vector<int> startTime = {1,2,6}, endTime = {3,5,9}, profit = {100, 10, 1};
    
    cout << soln.jobScheduling(startTime, endTime, profit) << endl;
    return 0;
}