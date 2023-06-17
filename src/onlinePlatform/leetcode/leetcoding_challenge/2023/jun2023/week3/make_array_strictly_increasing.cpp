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
const int IMPOSSIBLE = numeric_limits<int>::max() / 2;

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        arr2 = vector(arr2.begin(), arr2.end());
        sort(arr2.begin(), arr2.end());
        
        memo = vector<vector<vector<int>>>();
        for (int i = 0; i <= arr1.size(); ++i) {
            memo.push_back(vector<vector<int>>());
            for (int j = 0; j <= arr2.size(); ++j) {
                memo[i].push_back(vector<int>(2, UNINITIALIZED));
            }
        }
        
        int answer = findMin(arr1, arr2, 0, 0, false);
        if (answer == IMPOSSIBLE) {
            return -1;
        } else {
            return answer;
        }
    }
    
private:
    vector<vector<vector<int>>> memo;
    
    int findMin(vector<int>& arr1, vector<int>& arr2, int i, int j, bool isReplaced) {
        if (i >= arr1.size()) {
            return 0;
        }
        
        if (memo[i][j][isReplaced] != UNINITIALIZED) {
            return memo[i][j][isReplaced];
        }
        
        memo[i][j][isReplaced] = IMPOSSIBLE;
                
        if (isValid(arr1, arr2, i, j, isReplaced)) {
            memo[i][j][isReplaced] = min(
                memo[i][j][isReplaced],
                findMin(arr1, arr2, i + 1, j, false)
            );
        }
        
        int prev = getPrevNum(arr1, arr2, i, j, isReplaced);
        int nextJ = distance(arr2.begin(), upper_bound(arr2.begin() + j, arr2.end(), prev));
        if (nextJ < arr2.size()) {
            int answer = findMin(arr1, arr2, i + 1, nextJ + 1, true);
            if (answer < IMPOSSIBLE) {
                memo[i][j][isReplaced] = min(
                    memo[i][j][isReplaced],
                    1 + answer
                );                
            }
        }
        
        return memo[i][j][isReplaced];
    }
    
    bool isValid(vector<int>& arr1, vector<int>& arr2, int i, int j, bool isReplaced) {
        if (i == 0) {
            return true;
        } else {
            return arr1[i] > getPrevNum(arr1, arr2, i, j, isReplaced);
        }
    }
    
    int getPrevNum(vector<int>& arr1, vector<int>& arr2, int i, int j, bool isReplaced) {
        if (i == 0) {
            return numeric_limits<int>::min();
        } else {            
            return isReplaced ? arr2[j - 1] : arr1[i - 1];
        }
    }
};

class WASolution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        arr2 = vector(arr2.begin(), arr2.end());
        sort(arr2.begin(), arr2.end());
        
        memo = vector<vector<int>>();
        for (int i = 0; i <= arr1.size(); ++i) {
            memo.push_back(vector<int>((arr2.size() + 1) * 2, UNINITIALIZED));
        }
        
        int answer = findMin(arr1, arr2, 0, 0);
        if (answer == IMPOSSIBLE) {
            return -1;
        } else {
            return answer;
        }
    }
    
private:
    vector<vector<int>> memo;
    
    int findMin(vector<int>& arr1, vector<int>& arr2, int i, int j) {
        if (i >= arr1.size()) {
            return 0;
        }
        
        if (memo[i][j] != UNINITIALIZED) {
            return memo[i][j];
        }
        
        memo[i][j] = IMPOSSIBLE;
                
        if (isValid(arr1, arr2, i, j)) {
            int nextJ = hasReplaced(j) ? j + 1 : j;
            memo[i][j] = min(
                memo[i][j],
                findMin(arr1, arr2, i + 1, nextJ)
            );
        }
        
        int prev = i > 0 ? arr1[i - 1] : numeric_limits<int>::min();
        int nextJ = distance(arr2.begin(), upper_bound(arr2.begin() + (j + 1) / 2, arr2.end(), prev));
        if (nextJ < arr2.size()) {
            memo[i][j] = min(
                memo[i][j],
                1 + findMin(arr1, arr2, i + 1, nextJ * 2 + 1)
            );
            
        }
        
//         bool canReplace = j < 2 * arr2.size();
//         if (canReplace) {
//             int answer = IMPOSSIBLE;
//             if (isValid(arr1, arr2, i, j + 1)) {
//                 answer = 1 + findMin(arr1, arr2, i + 1, j + 1);
//             } else {
//                 answer = findMin(arr1, arr2, i, j + 1);
//             }
                        
//             memo[i][j] = min(
//                 memo[i][j],
//                 answer
//             );
//         }
        
        return memo[i][j];
    }
    
    bool isValid(vector<int>& arr1, vector<int>& arr2, int i, int j) {
        if (i == 0) {
            return true;
        } else {
            int prevNum = hasReplaced(j) ? arr2[(j - 1) / 2] : arr1[i - 1];
            return arr1[i] > prevNum;
        }
    }
    
    bool hasReplaced(int j) {
        return j % 2 != 0;
    }
};

int main() {
    Solution soln;

    vector<int> arr1 = {1,5,3,6,7};
    vector<int> arr2 = {1,3,2,4};

    cout << soln.makeArrayIncreasing(arr1, arr2) << endl;

    return 0;
}