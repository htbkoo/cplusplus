#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <limits>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iterator>
#include <sstream>
#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> blocked(begin(deadends), end(deadends));
          
        string START = "0000";
        
        deque<string> q;
        q.push_back(START);
        
        unordered_set<string> visited;
        int answer = 0;
        while (q.size() > 0) {
            int count = q.size();
            for (int i = 0; i < count; ++i) {
                string curr = q.front();
                q.pop_front();
                
                if (blocked.count(curr) > 0) {
                    continue;
                }
                
                if (visited.count(curr) > 0) {
                    continue;
                }
                visited.insert(curr);
                
                if (curr == target) {
                    return answer;
                }
                
                for (int j = 0; j < curr.size(); ++j) {
                    for (int d: {-1, 1}) {
                        string next = string(begin(curr), end(curr));
                        int digit = next[j] - '0';                        
                        next[j] = (char) ((digit + 10 + d) % 10 + '0');                        
                        q.push_back(next);
                    }
                }
            }
            
            answer++;
        }
        
        return -1;
    }
};
