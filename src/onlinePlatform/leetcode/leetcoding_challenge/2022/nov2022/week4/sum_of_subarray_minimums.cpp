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
    int sumSubarrayMins(vector<int>& arr) {
        long MOD = (long) pow(10, 9) + 7;
        
        vector<int> left = getBoundaries(arr, arr.size() - 1, -1, -1, false);
        vector<int> right = getBoundaries(arr, 0, arr.size(), 1, true);
        
        long answer = 0;
        for (int idx = 0; idx < arr.size(); idx++) {
            long val = arr[idx];
            long count = getCount(left, right, idx);
            answer = (answer + val * count) % MOD;
        }
        
        return (int) answer;
    }
    
private:
    long getCount(vector<int>& left, vector<int>& right, int idx) {
        int n = right[idx] - left[idx] + 1;
        int i = idx - left[idx];
        return (i + 1) * (n - i);
    }
    
    vector<int> getBoundaries(vector<int>& arr, int fromIdx, int toIdx, int dIdx, bool keepEqual) {
        vector<int> boundaries = vector<int>(arr.size());
        vector<int> stack;
        
        for (int idx = fromIdx; idx != toIdx; idx += dIdx) {
            while (stack.size() > 0) {
                int prevIdx = stack.back();
                bool shouldPop = arr[idx] < arr[prevIdx] || (!keepEqual && arr[idx] == arr[prevIdx]);
                
                if (shouldPop) {
                    boundaries[prevIdx] = idx - dIdx;
                    stack.pop_back();
                } else {
                    break;
                }
            }
            stack.push_back(idx);
        }
        
        int boundaryIdx = toIdx - dIdx;
        while (stack.size() > 0) {
            int idx = stack.back();
            stack.pop_back();
            
            boundaries[idx] = boundaryIdx;
        }
        
        return boundaries;
    }
};

int main() {
    Solution soln;
    // vector<int> arr = {3,1,2,4};
    vector<int> arr = {71,55,82,55};
    cout << soln.sumSubarrayMins(arr) << endl;
    return 0;
}