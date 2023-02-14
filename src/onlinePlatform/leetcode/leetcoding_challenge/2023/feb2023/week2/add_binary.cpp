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
    string addBinary(string a, string b) {
        vector<char> digits;
        
        int i = a.size() - 1, j = b.size() - 1;    
        int carry = 0;
                
        while (i >= 0 || j >= 0 || carry > 0) {
            int digitA = 0;
            if (i >= 0) {
                digitA = a[i] - '0';
                i--;
            }
            
            int digitB = 0;
            if (j >= 0) {
                digitB = b[j] - '0';
                j--;
            }
            
            int total = carry + digitA + digitB;
            
            char result = (total % 2) + '0';
            digits.push_back(result);
            
            carry = total / 2;
        }
        
        reverse(digits.begin(), digits.end());
        
        return string(digits.begin(), digits.end());
    }
};
