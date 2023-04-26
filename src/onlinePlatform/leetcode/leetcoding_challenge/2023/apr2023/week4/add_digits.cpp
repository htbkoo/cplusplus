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
    int addDigits(int num) {
        // TODO: validate input, what if num < 0 ?
        while (num > 9) {
            num = getDigitsSum(num);
        }
        
        return num;
    }
    
private:
    int getDigitsSum(int num) {
        int total = 0;
        while (num > 0) {
            total += num % 10;
            num /= 10;
        }
        return total;
    }
};