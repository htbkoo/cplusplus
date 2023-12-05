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
    int numberOfMatches(int n) {
        int answer = 0;

        while (n > 1) {
            if (n % 2 == 0) {
                answer += n / 2;
                n /= 2;
            } else {
                answer += (n - 1) / 2;
                n = (n - 1) / 2 + 1;
            }
        }

        return answer;
    }
};