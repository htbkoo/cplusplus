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
    int minKBitFlips(vector<int>& nums, int k) {
        deque<int> currFlips;

        int answer = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (currFlips.size() > 0 && i >= (k + currFlips[0])) {
                currFlips.pop_front();
            }

            if ((currFlips.size() + nums[i]) % 2 == 0) {
                if (i + k > nums.size()) {
                    return -1;
                }

                answer++;
                currFlips.push_back(i);
            }
        }

        return answer;
    }
};
