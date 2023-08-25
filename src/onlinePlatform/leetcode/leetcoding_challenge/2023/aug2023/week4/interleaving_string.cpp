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
const int TRUE = 1;
const int FALSE = 0;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        
        for (int i = 0; i <= s1.size(); ++i) {
            memo.push_back(vector<int>(s2.size() + 1, UNINITIALIZED));
        }
        
        return TRUE == canInterleave(s1, s2, s3, 0, 0);
    }
    
private:
    vector<vector<int>> memo;
    
    int canInterleave(string& s1, string& s2, string& s3, int i, int j) {
        int k = i + j;
        if (k == s3.size()) {
            return TRUE;
        }
        if (memo[i][j] != UNINITIALIZED) {
            return memo[i][j];
        }
       
        memo[i][j] = (i < s1.size() && s1[i] == s3[k] && canInterleave(s1, s2, s3, i + 1, j)) || (j < s2.size() && s2[j] == s3[k] && canInterleave(s1, s2, s3, i, j + 1)) ;
        return memo[i][j];
    }
};