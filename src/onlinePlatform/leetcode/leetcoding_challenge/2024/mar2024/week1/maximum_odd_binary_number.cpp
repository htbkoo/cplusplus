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
    string maximumOddBinaryNumber(string s) {
        int numOnes = 0;
        for (auto ch: s) {
            if (ch == '1') {
                numOnes++;
            }
        }

        string answer;
        for (int i = 0; i < s.size() - 1; ++i) {
            if (numOnes > 1) {
                answer += "1";
                numOnes--;
            } else {
                answer += "0";
            }
        }

        answer += "1";

        return answer;
    }
};


