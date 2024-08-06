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
    int minimumPushes(string word) {
        unordered_map<char, int> counter;
        for (auto ch: word) {
            counter[ch]++;
        }

        vector<int> counts;
        for (auto &[_, count]: counter) {
            counts.push_back(count);
        }
        sort(begin(counts), end(counts), greater<int>());


        int NUM_KEYS = 8;
        int idx = 0;
        int cycle = 1;
        int answer = 0;
        for (auto count: counts) {
            answer += cycle * count;
            idx++;
            if (idx == NUM_KEYS) {
                idx = 0;
                cycle++;
            }
        }
        return answer;
    }
};
