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
    int totalFruit(vector<int>& fruits) {
        int MAX_NUM_TYPE_FRUITS = 2;
        
        unordered_map<int, int> counter;
            
        int answer = 0;
        int currCount = 0;
        
        int left = 0;
        
        for (int fruit: fruits) {
            currCount++;
            counter[fruit]++;
            
            while (counter.size() > MAX_NUM_TYPE_FRUITS) {
                currCount--;
                int removedFruit = fruits[left];
                counter[removedFruit]--;
                if (counter[removedFruit] == 0) {
                    counter.erase(removedFruit);
                }
                
                left++;
            }
            
            answer = max(answer, currCount);
        }
        
        return answer;
    }
};
