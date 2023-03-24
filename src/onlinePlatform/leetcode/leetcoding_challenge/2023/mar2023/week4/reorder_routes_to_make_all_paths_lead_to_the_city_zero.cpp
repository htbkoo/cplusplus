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
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, unordered_set<int>> parents;
        unordered_map<int, unordered_set<int>> children;
        for (auto& connection: connections) {
            int a = connection[0], b = connection[1];
            parents[a].insert(b);
            children[b].insert(a);
        }
        
        int START = 0;
        int NO_PREV = -1;
        int answer = 0;
        
        vector<pair<int, int>> stack{pair{START, NO_PREV}};
        while (stack.size() > 0) {
            auto [curr, prev] = stack.back();
            stack.pop_back();
            
            for (auto nextCity: parents[curr]) {
                if (nextCity != prev) {
                    answer++;
                    stack.push_back(pair{nextCity, curr});
                }
            }
            for (auto nextCity: children[curr]) {
                if (nextCity != prev) {
                    stack.push_back(pair{nextCity, curr});
                }
            }
        }
        
        return answer;
    }
};
