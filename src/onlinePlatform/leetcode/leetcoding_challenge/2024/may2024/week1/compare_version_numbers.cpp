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
    int compareVersion(string version1, string version2) {
        auto v1 = split(version1);
        auto v2 = split(version2);
        
        for (int i = 0; i < max(v1.size(), v2.size()); ++i) {
            auto r1 = i >= v1.size() ? 0 : v1[i];
            auto r2 = i >= v2.size() ? 0 : v2[i];
            
            if (r1 > r2) {
                return 1;
            } else if (r1 < r2) {
                return -1;
            }
        }
        
        return 0;
    }
    
private:
    vector<int> split(string& version) {
        vector<int> v;
        string curr = "";
        
        for (auto ch: version) {
            if (ch == '.') {
                v.push_back(stoi(curr));
                curr = "";
            } else {
                curr += ch;
            }
        }
        
        v.push_back(stoi(curr));        
        return v;
    }
};
