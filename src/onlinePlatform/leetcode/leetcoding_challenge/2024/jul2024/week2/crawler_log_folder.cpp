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
    int minOperations(vector<string>& logs) {
        int count = 0;

        for (auto log: logs) {
            if (log == "../") {
                count = max(0, count - 1);
            } else if (log != "./") {
                count++;
            }
        }

        return count;
    }
};
