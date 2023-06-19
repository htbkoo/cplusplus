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
    int largestAltitude(vector<int>& gain) {
        int answer = 0;
        int curr = 0;
        for (auto diff: gain) {
            curr += diff;
            answer = max(answer, curr);
        }
        return answer;
    }
};