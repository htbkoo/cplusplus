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
    int maxCoins(vector<int>& piles) {
        sort(begin(piles), end(piles));

        int answer = 0;
        int left = 0, right = piles.size() - 1;

        while (left < right) {
            answer += piles[right - 1];
            left++;
            right -= 2;
        }

        return answer;
    }
};
