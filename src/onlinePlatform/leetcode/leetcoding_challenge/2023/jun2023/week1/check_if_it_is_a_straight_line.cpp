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
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int dy = coordinates[0][1] - coordinates[1][1];
        int dx = coordinates[0][0] - coordinates[1][0];
        
        for (int i = 2; i < coordinates.size(); ++i) {
            if ( (dx *(coordinates[0][1] - coordinates[i][1])) != (dy *(coordinates[0][0] - coordinates[i][0])) ) {
                return false;
            } 
        }
        
        return true;
    }
};