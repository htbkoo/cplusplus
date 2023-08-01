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
    vector<vector<int>> combine(int n, int k) {
        return c(n, k, 1);        
    }
    
private:
    vector<vector<int>> c(int n, int k, int start) {
        if (k == 0) {
            return {};
        }
        
        vector<vector<int>> answer;
        if (k == 1) {            
            for (int i = start; i <= n; i++) {
                answer.push_back({i});
            }
            return answer;
        }
        
        for (int i = start; i <= n; i++) {
            vector<vector<int>> tails = c(n, k - 1, i + 1);
            for (auto tail: tails) {
                vector<int> v = {i};
                v.insert(v.end(), tail.begin(), tail.end());
                answer.push_back(v);
            }
        }

        return answer;
    }
};