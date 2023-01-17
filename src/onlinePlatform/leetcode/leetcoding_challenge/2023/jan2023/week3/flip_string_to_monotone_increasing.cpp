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
    int minFlipsMonoIncr(string s) {
        vector<int> numOnesOnLeft = vector<int>({0, 0});
        for (int i = 0; i < s.size(); i++) {            
            int count = numOnesOnLeft.back();
            if (s[i] == '1') {
                count++;
            }
            numOnesOnLeft.push_back(count);
        }
        
        vector<int> numZeroesOnRight = vector<int>({0, 0});
        for (int i = s.size() - 1; i >= 0; i--) {            
            int count = numZeroesOnRight.back();
            if (s[i] == '0') {
                count++;
            }
            numZeroesOnRight.push_back(count);
        }
        
        reverse(numOnesOnLeft.begin(), numOnesOnLeft.end());
        
        int answer = numOnesOnLeft[0] + numZeroesOnRight[0];
        for (int i = 1; i < numOnesOnLeft.size(); i++) {
            int total = numOnesOnLeft[i] + numZeroesOnRight[i];
            answer = min(answer, total);
        }
            
        return answer;
    }
};