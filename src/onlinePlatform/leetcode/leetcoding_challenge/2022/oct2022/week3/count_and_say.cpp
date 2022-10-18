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
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        
        string prev = countAndSay(n - 1);
        stringstream ss;
        
        int left = 0;
        int count = 0;
        for (int i = 0; i <= prev.size(); i++) {
            if (i == prev.size() || prev[i] != prev[left]) {
                // ss << to_string(count) << to_string(prev[left]);
                ss << to_string(count) << prev[left];
                
                left = i;
                count = 0;
            }
            
            count++;
        }
        
        return ss.str();
    }
};

int main() {
    Solution soln;
    cout << soln.countAndSay(4) << endl;
}