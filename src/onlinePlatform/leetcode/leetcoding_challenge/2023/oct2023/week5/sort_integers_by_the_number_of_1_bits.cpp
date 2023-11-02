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
    vector<int> sortByBits(vector<int>& arr) {
        sort(begin(arr), end(arr), [&](int a, int b) { return countBit(a) < countBit(b); });
        return arr;        
    }
    
private:
    int countBit(int num) {
        int count = 0;
        while (num > 0) {
            count += num % 2;
            num /= 2;            
        }
        return count;
    }
};