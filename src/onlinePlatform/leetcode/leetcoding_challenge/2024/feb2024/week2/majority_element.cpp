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
    int majorityElement(vector<int>& nums) {
        // TODO: validate, what if nums.size() == 0?

        int element = nums[0];
        int count = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == element) {
                count++;
            } else {
                if (count > 1) {
                    count--;
                } else {
                    element = nums[i];
                }
            }
        }

        return element;
    }
};