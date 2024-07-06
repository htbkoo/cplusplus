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
    int passThePillow(int n, int time) {
        if (n == 1) {
            return 1;
        }

        int dir = 1;
        int curr = 1;

        for (int i = 0; i < time; i++) {
            curr += dir;
            if (curr == n || curr == 1) {
                dir *= -1;
            }
        }

        return curr;
    }
};
