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
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        
        int answer = 0;
        int lo = 0, hi = people.size() - 1;
        
        while (lo <= hi) {
            answer++;
            if (people[hi] + people[lo] <= limit) {
                hi--;
                lo++;
            } else {
                hi--;
            }
        }
        
        return answer;
    }
};
