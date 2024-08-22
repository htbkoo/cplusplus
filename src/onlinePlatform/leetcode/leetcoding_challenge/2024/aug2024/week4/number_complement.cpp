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
    int findComplement(int num) {
        int answer = 0;
        int base = 1;
        while (num > 1) {
            if (num % 2 == 0) {
                answer += base ;
            }
            num /= 2;
            base *= 2;
        }
        
        return answer;
    }
};
