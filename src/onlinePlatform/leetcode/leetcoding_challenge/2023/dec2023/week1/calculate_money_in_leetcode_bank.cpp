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
    int totalMoney(int n) {
        int answer = 0;

        for (int i = 1; i <= n; ++i) {
            int week = (i - 1) / 7 + 1;
            int weekday = (i - 1) % 7;

            answer += week + weekday;
        }

        return answer;
    }
};