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
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        auto rowIndices = tsort(k, rowConditions);        
        if (rowIndices.size() == 0) {
            return {};
        }
        
        auto colIndices = tsort(k, colConditions);        
        if (colIndices.size() == 0) {
            return {};
        }
        
        vector<vector<int>> answer(k, vector<int>(k, 0));
        
        for (int i = 0; i < k; ++i) {
            auto y = rowIndices[i];
            auto x = colIndices[i];
            answer[y][x] = i + 1; 
        }
        
        return answer;
        
    }
    
private:
    vector<int> tsort(int k, vector<vector<int>>& conditions) {
        vector<unordered_set<int>> parents(k, unordered_set<int>());
        vector<int> outdegrees(k, 0);
        
        for (auto &condition: conditions) {
            auto first = condition[0] - 1;
            auto second = condition[1] - 1;
            
            // TODO: validate first != second            
            if (parents[second].count(first) == 0) {
                parents[second].insert(first);
                outdegrees[first]++;
            }
        }

        deque<int> candidates;
        for (int i = 0; i < k; ++i) {
            if (outdegrees[i] == 0) {
                candidates.push_back(i);
            }
        }
        
        int assignedCount = 0;
        int curr = k - 1;

        vector<int> indices(k, k - 1);
        
        while (candidates.size() > 0) {
            int count = candidates.size();
            for (int i = 0; i < count; ++i) {
                auto child = candidates.front();
                candidates.pop_front();
                
                assignedCount++;
                indices[child] = curr;
                for (auto p: parents[child]) {
                    outdegrees[p]--;
                    if (outdegrees[p] == 0) {
                        candidates.push_back(p);
                    }
                }
            }
            curr--;
        }
        
        if (assignedCount < k) {
            return {};
        }
        
        return indices;
    }
};

int main() {
    Solution soln;

    vector<vector<int>> rowConditions = {{1,2},{3,2}}, colConditions = {{2,1},{3,2}};

    auto answer = soln.buildMatrix(3, rowConditions, colConditions);
    
    return 0;
}
