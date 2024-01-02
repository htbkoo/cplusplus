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
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<unordered_set<int>> sets;


        for (auto num: nums) {
            bool added = false;
            for (int i = 0; i < answer.size(); ++i) {
                if (sets[i].count(num) == 0) {
                    answer[i].push_back(num);
                    sets[i].insert(num);
                    added = true;
                    break;
                }
            }
            if (!added) {
                answer.push_back(vector<int>{num});
                sets.push_back(unordered_set<int>({num}));
            }
        }

        return answer;
    }
};