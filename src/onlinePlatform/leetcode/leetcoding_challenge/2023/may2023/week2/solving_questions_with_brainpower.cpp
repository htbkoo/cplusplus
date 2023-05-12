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
#include <cstring> // for memset
using namespace std; // since cin and cout are both in namespace std, this saves some text

const int MAX_NUM_QUESTIONS = 1e5;

const int UNINITIALIZED = -1;
    
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        memset(memo, UNINITIALIZED, sizeof(memo));
        
        return findMax(questions, 0);
    }
    
private:
    long long memo[MAX_NUM_QUESTIONS + 1];
    
    long long findMax(vector<vector<int>>& questions, int i) {
        if (i >= questions.size()) {
            return 0;
        }
        
        if (memo[i] != UNINITIALIZED) {
            return memo[i];
        }
        
        int points = questions[i][0];
        int brainpower = questions[i][1];
        
        memo[i] = max(
            findMax(questions, i + 1), // skip
            (long long) points + findMax(questions, i + 1 + brainpower)
        );
        
        return memo[i];
    }
};