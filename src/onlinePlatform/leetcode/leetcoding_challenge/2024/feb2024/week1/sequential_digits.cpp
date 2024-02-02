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
    vector<int> sequentialDigits(int low, int high) {
        vector<int> answer;
        for (int start = 1; start <= 9; ++start) {
            int curr = start;
            while (curr <= high) {
                if (curr >= low) {
                    answer.push_back(curr);
                }
                int lastDigit = curr % 10;
                if (lastDigit >= 9) {
                    break;
                }
                curr = 10 * curr + (lastDigit + 1);
            }
        }

        sort(begin(answer), end(answer));
        return answer;
    }
};
