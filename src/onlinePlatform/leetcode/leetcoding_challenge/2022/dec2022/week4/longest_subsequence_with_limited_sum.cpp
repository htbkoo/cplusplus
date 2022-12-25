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
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        
        vector<int> prefixSums = {0};
        for (int num: nums) {
            prefixSums.push_back(prefixSums.back() + num);
        }
        
        vector<int> answer(queries.size());
        for (int i = 0; i < answer.size(); i++) {
            answer[i] = solve(prefixSums, queries[i]);
        }
        return answer;
    }
    
private:
    int solve(vector<int>& prefixSums, int query) {
        return max(
            (int) 0,
            (int) distance(
                prefixSums.begin(), 
                upper_bound(prefixSums.begin(), prefixSums.end(), query)
            ) - 1
        );
    }
};

int main() {
    Solution soln;
    vector<int> nums = {4,5,2,1};
    vector<int> queries = {3,10,21};

    auto temp = soln.answerQueries(nums, queries);
    cout << "" << endl;
}