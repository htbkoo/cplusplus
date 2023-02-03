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
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        
        vector<vector<char>> rows(numRows);
        
        int currRow = 0;
        int dir = 1;
        for (char ch: s) {
            rows[currRow].push_back(ch);
            
            if (dir == 1) {
                currRow++;
                if (currRow >= numRows) {
                    currRow = numRows - 2;
                    dir = -1;
                }
            } else if (dir == -1) {
                currRow--;
                if (currRow < 0) {
                    currRow = 1;
                    dir = 1;
                }
            }            
        }
        
        string answer;
        for (vector<char> row: rows) {
            string part(row.begin(), row.end());
            answer += part;
        }
        
        return answer;
    }
};