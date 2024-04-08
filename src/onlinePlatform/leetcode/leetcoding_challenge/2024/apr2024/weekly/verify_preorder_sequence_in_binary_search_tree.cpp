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
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        reverse(begin(sandwiches), end(sandwiches));
        
        vector<int> counter(2, 0);
        for (auto s: students) {
            counter[s]++;
        }
        
        deque<int> d(begin(students), end(students));
        
        while (sandwiches.size() > 0 && d.size() > 0 && counter[sandwiches.back()] > 0) {
            if (sandwiches.back() == d.front()) {
                counter[sandwiches.back()]--;
                d.pop_front();
                sandwiches.pop_back();                
            } else {
                d.push_back(d.front());                
                d.pop_front();
            }
        }
        
        return d.size();
    }
};
