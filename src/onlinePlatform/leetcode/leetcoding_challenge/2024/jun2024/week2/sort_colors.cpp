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
    void sortColors(vector<int>& nums) {
        vector<int> counter(3, 0);

        for (auto num: nums) {
            counter[num]++;
        }

        int i = 0;
        for (int num = 0; num <= 2; ++num) {
            for (int j = 0; j < counter[num]; ++j) {
                nums[i] = num;
                i++;
            }
        }
    }
};
