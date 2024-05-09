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
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long answer = 0;

        sort(begin(happiness), end(happiness), std::greater<int>());

        for (int i = 0; i < k; ++i) {
            answer += max(0, happiness[i] - i);
        }

        return answer;
    }
};

class WASolution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int answer = 0;

        sort(begin(happiness), end(happiness), std::greater<int>());

        for (int i = 0; i < k; ++i) {
            answer += max(0, happiness[i] - i);
        }

        return answer;
    }
};
