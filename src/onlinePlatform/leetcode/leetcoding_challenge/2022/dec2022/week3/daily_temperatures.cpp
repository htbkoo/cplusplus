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
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer = vector<int>(temperatures.size());
        vector<int> stack;
        
        for (int i = temperatures.size() - 1; i >= 0; i--) {
            int currTemperature = temperatures[i];
            while (stack.size() > 0) {
                int prevTemperature = temperatures[stack.back()];
                if (prevTemperature > currTemperature) {
                    answer[i] = stack.back() - i;                    
                    break;
                } else {
                    stack.pop_back();
                }
            }
            
            stack.push_back(i);
        }
        
        return answer;
    }
};