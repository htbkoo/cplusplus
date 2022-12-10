#include <unordered_map>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        parents = unordered_map<int, int>();
        sums = unordered_map<int, long long>();

        long long currMax = 0;
        vector<long long> answers;
        
        for (int i = removeQueries.size() - 1; i >= 0; i--) {
            answers.push_back(currMax);
            
            int query = removeQueries[i];
            sums[query] = nums[query];
            parents[query] = query;
            
            currMax = max(currMax, sums[query]);
            
            for (int neighbour: {query - 1, query + 1}) {
                if (parents.count(neighbour) > 0) {
                    currMax = max(currMax, u(query, neighbour));
                }
            }
        }
        
        reverse(answers.begin(), answers.end());        
        return answers;
    }
    
private:
    unordered_map<int, int> parents;
    unordered_map<int, long long> sums;

    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }
    
    long long u(int x, int y) {
        x = find(x);
        y = find(y);
        
        if (x != y) {
            parents[y] = x;
            sums[x] += sums[y];
        }
        return sums[x];       
    }
};

int main() {
    Solution soln;

    vector<int> nums = {1,2,5,6,1};
    vector<int> removeQueries = {0,3,2,4,1};
    auto answers = soln.maximumSegmentSum(nums, removeQueries);


}