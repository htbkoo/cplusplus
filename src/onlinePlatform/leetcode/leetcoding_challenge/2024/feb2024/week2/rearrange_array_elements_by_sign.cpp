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
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> answer(nums.size(), -1);
        int posIdx = 0;
        int negIdx = 1;

        for (auto num: nums) {
            if (num > 0) {
                answer[posIdx] = num;
                posIdx += 2;
            } else if (num < 0) {
                answer[negIdx] = num;
                negIdx += 2;
            }
            // TODO: handle num == 0 case
        }

        return answer;
    }
};
