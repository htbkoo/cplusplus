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
    double average(vector<int>& salary) {
        if (salary.size() <= 2) {
            // TODO: confirm this;
            return 0;
        }
        
        long long total = 0;
        for (auto s: salary) {
            total += s;
        }
        
        int maxSalary = *max_element(salary.begin(), salary.end());
        int minSalary = *min_element(salary.begin(), salary.end());
        
        long long excludedTotal = total - maxSalary - minSalary;
        
        return (double) excludedTotal / (double) (salary.size() - 2);
    }
};