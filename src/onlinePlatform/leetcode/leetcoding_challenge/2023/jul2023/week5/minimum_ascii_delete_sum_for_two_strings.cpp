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
    int minimumDeleteSum(string s1, string s2) {
        memo = vector<vector<int>>();
        for (int i = 0; i <= s1.size(); ++i) {
            memo.push_back(vector<int>(s2.size() + 1, UNINITIALIZED));
        }
        
        return findMin(s1, s2, 0, 0);
    }
    
private:
    vector<vector<int>> memo;
    
    int findMin(string& s1, string& s2, int i, int j) {
        if (memo[i][j] != UNINITIALIZED) {            
            return memo[i][j];
        }
        if (i >= s1.size() && j >= s2.size()) {
            memo[i][j] = 0;
            return memo[i][j];
        }
        if (i >= s1.size()) {
            memo[i][j] = s2[j] + findMin(s1, s2, i, j + 1);
            return memo[i][j];
        }
        if (j >= s2.size()) {
            memo[i][j] = s1[i] + findMin(s1, s2, i + 1, j);
            return memo[i][j];
        }
        if (s1[i] == s2[j]) {
            memo[i][j] = findMin(s1, s2, i + 1, j + 1);
        } else {
            memo[i][j] = min(
                s1[i] + findMin(s1, s2, i + 1, j),
                min(
                    s2[j] + findMin(s1, s2, i, j + 1),
                    s1[i] + s2[j] + findMin(s1, s2, i + 1, j + 1)
                )
            );
        }
        
        return memo[i][j];
    }
};