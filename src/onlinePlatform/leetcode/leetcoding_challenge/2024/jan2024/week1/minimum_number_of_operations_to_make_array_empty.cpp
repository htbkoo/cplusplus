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
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> counter;

        for (auto num: nums) {
            counter[num]++;
        }

        int answer = 0;
        for (auto& [num, count]: counter) {
            if (count == 1) {
                return -1;
            }
            answer += (2 + count) / 3;
        }

        return answer;
    }
};
