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
    int maxFrequencyElements(vector<int>& nums) {
        // TODO: what if nums is empty?
        int maxFreq = 0;
        unordered_map<int, int> counter;
        for (auto num: nums) {
            counter[num]++;
            maxFreq = max(maxFreq, counter[num]);
        }

        int answer = 0;
        for (auto& [num, cnt]: counter) {
            if (cnt == maxFreq) {
                answer += cnt;
            }
        }

        return answer;
    }
};
