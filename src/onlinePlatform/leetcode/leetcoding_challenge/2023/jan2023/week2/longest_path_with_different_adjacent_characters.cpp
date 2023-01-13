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
    int longestPath(vector<int>& parent, string s) {
        int ROOT = 0;
        
        answer = 0;
        
        unordered_map<int, vector<int>> childrens;
        for (int i = ROOT + 1; i < parent.size(); i++) {
            int p = parent[i];
            childrens[p].push_back(i);
        }
        
        dfs(ROOT, childrens, s);
        return answer;
    }
    
private:
    int answer;
    
    int dfs(
        int node, 
        unordered_map<int, vector<int>>& childrens,
        string& s
    ) {
        int length = 1;
        int longest = numeric_limits<int>::min();
        int second = numeric_limits<int>::min();
        
        char ch = s[node];
        for (int child: childrens[node]) {
            int childLength = dfs(child, childrens, s);
            if (s[child] != ch) {
                if (childLength > longest) {
                    second = longest;
                    longest = childLength;
                } else if (childLength > second) {
                    second = childLength;
                }
            }
        }
        
        answer = max({
            (long) answer,
            (long) length,
            (long) length + (long) longest,
            (long) length + (long) longest + (long) second
        });
        
        return max(
            (long) length,
            (long) length + (long) longest
        );
    }
};