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
    int maximum69Number (int num) {
        string temp = to_string(num);
        for (char& digit: temp) {
            if (digit == '6') {
                digit = '9';
                break;
            }
        }
        
        return stoi(temp);
    }
};
