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
    vector<int> getRow(int rowIndex) {
        vector<int> row{1};
        
        for (int i = 0; i < rowIndex; ++i) {
            long num = (long) row.back() * (rowIndex - i) / (i + 1);
            row.push_back(num);
        }
        
        return row;
    }
};