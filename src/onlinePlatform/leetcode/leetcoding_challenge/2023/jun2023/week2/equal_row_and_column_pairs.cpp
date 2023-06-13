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
    int equalPairs(vector<vector<int>>& grid) {
        const string SEPARATOR = "_";
        
        int height = grid.size();
        int width = grid[0].size();
        
        unordered_map<string, int> pairs;        
        for (int y = 0; y < height; ++y) {
            string p = join(grid[y], SEPARATOR);
            pairs[p]++;
        }
        
        int answer = 0;
        for (int x = 0; x < width; ++x) {
            vector<int> col;
            for (int y = 0; y < height; ++y) {
                col.push_back(grid[y][x]);
            }
            
            string p = join(col, SEPARATOR);
            answer += pairs[p];
        }
        
        return answer;
    }
    
private:
    string join(vector<int>& v, string sep) {
        if (v.size() == 0) {
            return "";
        }
        
        string s;
        s.reserve(v.size() * 8); 
        
        s += to_string(v[0]);
        
        for (int i = 1; i < v.size(); i++) {
            s += sep + to_string(v[i]);
        }
        
        return s;
    }
};