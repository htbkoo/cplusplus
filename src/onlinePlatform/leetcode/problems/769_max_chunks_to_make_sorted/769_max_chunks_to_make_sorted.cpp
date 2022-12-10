#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> positions = vector<int>(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            int num = arr[i];
            positions[num] = i;
        }
        
        for (int num = 1; num < arr.size(); num++) {
            positions[num] = max(positions[num], positions[num - 1]);
        }
        
        int answer = arr.size();
        int prev = 0;
        int curr = 0;
        
        for (int num = 0; num < arr.size(); num++) {
            int until = positions[num];
            while (curr <= until) {
                until = max(until, positions[arr[curr]]);
                curr++;
            }
            answer -= max(0, curr - 1 - prev);            
            prev = curr;
        }
        return answer;
    }
};