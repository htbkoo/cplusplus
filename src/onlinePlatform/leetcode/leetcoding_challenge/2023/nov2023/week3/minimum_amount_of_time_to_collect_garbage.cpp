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
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        if (garbage.size() == 0) {
            return 0;
        }

        vector<string> GARBAGE_TYPES{"M", "P", "G"};

        vector<int> prefix{0};

        vector<int> rightmost(GARBAGE_TYPES.size(), 0);

        int answer = garbage[0].size();
        for (int i = 1; i < garbage.size(); ++i) {
            answer += garbage[i].size();

            prefix.push_back(prefix.back() + travel[i - 1]);

            for (int t = 0; t < GARBAGE_TYPES.size(); ++t) {
                if (garbage[i].find(GARBAGE_TYPES[t]) != -1) {
                    rightmost[t] = i;
                }
            }
        }

        for (int t = 0; t < GARBAGE_TYPES.size(); ++t) {
            answer += prefix[rightmost[t]];
        }

        return answer;
    }
};