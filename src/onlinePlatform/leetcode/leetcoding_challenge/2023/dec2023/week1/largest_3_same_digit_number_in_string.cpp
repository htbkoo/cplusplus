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
    string largestGoodInteger(string num) {
        for (char ch = '9'; ch >= '0'; --ch) {
            string pat = "";
            for (int i = 0; i < 3; ++i) {
                pat += ch;
            }

            if (num.find(pat) != -1) {
                return pat;
            }
        }
        return "";
    }
};

int main() {
    Solution soln;
    cout << soln.largestGoodInteger("6777133339") << endl;
    cout << soln.largestGoodInteger("2300019") << endl;
    cout << soln.largestGoodInteger("42352338") << endl;
    return 0;
}