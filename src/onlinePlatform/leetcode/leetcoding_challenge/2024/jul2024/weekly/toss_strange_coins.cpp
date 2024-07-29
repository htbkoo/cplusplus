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
    double probabilityOfHeads(vector<double>& prob, int target) {
        memo = vector<vector<double>>(prob.size() + 1, vector<double>(target + 1, UNINITIALIZED));
        
        return compute(prob, 0, target);
    }
    
private:
    vector<vector<double>> memo;

    double compute(vector<double>& prob, int i, int remain) {
        if (i >= prob.size()) {
            if (remain == 0) {
                return 1;
            } else {
                return 0;
            }
        }
        
        if (remain < 0) {
            return 0;
        }
        
        if (memo[i][remain] == UNINITIALIZED) {            
            auto yes = prob[i] * compute(prob, i + 1, remain - 1);
            auto no = (1 - prob[i])  * compute(prob, i + 1, remain);
            memo[i][remain] = yes + no;
        }
        
        return memo[i][remain];
    }
};
