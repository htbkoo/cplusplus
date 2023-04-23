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
#include <cstring> // for memset
using namespace std; // since cin and cout are both in namespace std, this saves some text

class Solution {
public:
    int numberOfArrays(string s, int k) {
        const int MOD = 1e9 + 7;
        const int ZERO_CHAR_CODE = (int) '0';
        
        int kSize = to_string(k).size();
        
        int numWays[kSize+1];
        memset(numWays, 0, sizeof(numWays));

        numWays[s.size() % (kSize + 1)] = 1;
        
        for (int start = s.size() - 1; start >= 0; --start) {
            if (s[start] == '0') {
                continue;
            }
            
            int num = 0;
            int i = start;
            while (i < s.size()) {
                num = num * 10 + (s[i] - ZERO_CHAR_CODE);
                if (num > k) {
                    break;
                }
                numWays[start % (kSize + 1)] = (numWays[start % (kSize + 1)] + numWays[(i + 1) % (kSize + 1)]) % MOD;
                i++;
            }
        }
        
        return numWays[0];
    }
};

int main() {
    Solution soln;

    cout << soln.numberOfArrays("1317", 2000) << endl;

    return 0;
}