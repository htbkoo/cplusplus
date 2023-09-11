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
const int MOD = 1e9 + 7;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> groupBySize;
        
        for (int i = 0; i < groupSizes.size(); ++i) {
            int groupSize = groupSizes[i];
            groupBySize[groupSize].push_back(i);
        }
        
        vector<vector<int>> answer;
        for (auto& [groupSize, people]: groupBySize) {
            // TODO: what if it is invalid / impossible to group?
            int numGroup = people.size() / groupSize;
            for (int i = 0; i < numGroup; ++i) {
                vector<int> group;
                for (int j = 0; j < groupSize; j++) {
                    int idx = i * groupSize + j;
                    group.push_back(people[idx]);
                }
                answer.push_back(group);
            }
                
        }
        
        return answer;
    }
};
