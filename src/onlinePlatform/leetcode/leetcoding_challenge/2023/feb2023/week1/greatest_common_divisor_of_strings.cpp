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
    string gcdOfStrings(string str1, string str2) {
        if (str1.size() > str2.size()) {
            string temp = str1;
            str1 = str2;
            str2 = temp;
        }
        
        string answer = "";
        for (int i = 1; i <= str1.size(); i++) {
            string divisor = str1.substr(0, i);
            if (isDivisible(str1, divisor) && isDivisible(str2, divisor)) {
                answer = divisor;
            }
        }
        return answer;
    }
    
private:
    bool isDivisible(string& str, string& divisor) {
        if (str.size() % divisor.size() != 0) {
            return false;
        }
        for (int begin = 0; begin < str.size(); begin+=divisor.size()) {
            if (str.substr(begin, divisor.size()) != divisor) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution soln;

    cout << soln.gcdOfStrings("ABCABC", "ABC") << endl;
    return 0;
}