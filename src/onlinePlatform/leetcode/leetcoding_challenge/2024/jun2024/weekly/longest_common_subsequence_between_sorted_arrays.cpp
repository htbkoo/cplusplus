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
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        int MAX_NUM = 100;
        vector<int> counts(MAX_NUM + 1, 0);

        for (auto arr: arrays) {
            for (auto num: arr) {
                counts[num]++;
            }
        }

        vector<int> answer;
        for (int i = 0; i <= MAX_NUM; ++i) {
            if (counts[i] == arrays.size()) {
                answer.push_back(i);
            }
        }

        return answer;
    }
};
