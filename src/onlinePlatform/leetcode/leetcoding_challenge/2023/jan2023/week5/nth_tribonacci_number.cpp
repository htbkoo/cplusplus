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
    int tribonacci(int n) {
        if (n == 0) {
            return 0;
        }
        
        if (n == 1) {
            return 1;
        }
        
        if (n == 2) {
            return 1;
        }
        
        int first = 0, second = 1, third = 1;
        
        for (int i = 3; i <= n; i++) {
            int total = first + second + third;
            first = second;
            second = third;
            third = total;
        }
        
        return third;
    }
};