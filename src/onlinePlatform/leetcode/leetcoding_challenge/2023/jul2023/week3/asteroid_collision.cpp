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
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> answer;
        
        for (auto asteroid: asteroids) {
            while (asteroid < 0 && answer.size() > 0) {
                int last = answer.back();
                if (last < 0) {
                    break;
                }
                
                if (abs(asteroid) > abs(last)) {
                    answer.pop_back();
                } else if (abs(asteroid) < abs(last)) {
                    asteroid = 0;
                } else {
                    answer.pop_back();
                    asteroid = 0;                    
                }
            }
            
            if (asteroid != 0) {
                answer.push_back(asteroid);
            }
        }
        
        return answer;
    }
};
