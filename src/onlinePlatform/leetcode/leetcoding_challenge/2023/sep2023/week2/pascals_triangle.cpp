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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer;
        
        for (int level = 1; level <= numRows; ++level) {
            answer.push_back({1});
            for (int i = 1; i < level; ++i) {
                int value = answer[answer.size() - 2][i - 1];
                if (i < answer[answer.size() - 2].size()) {
                    value += answer[answer.size() - 2][i];
                }
                answer.back().push_back(value);
            }
        }
        
        return answer;
    }
};