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
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();

        unordered_set<string> s(begin(nums), end(nums));

        for (int i = 0; i < (int) pow(2, n); ++i) {
            string binary = asBinary(i, n);
            if (s.count(binary) == 0) {
                return binary;
            }
        }

        return "";
    }

private:
    string asBinary(int i, int n) {
        string b;
        for (int j = 0; j < n; ++j) {
            if (i > 0) {
                b += to_string(i % 2);
                i /= 2;
            } else {
                b += "0";
            }
        }
        reverse(begin(b), end(b));
        return b;
    }
};