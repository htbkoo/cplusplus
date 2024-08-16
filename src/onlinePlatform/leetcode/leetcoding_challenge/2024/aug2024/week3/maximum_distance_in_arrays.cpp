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
    int maxDistance(vector<vector<int>>& arrays) {
        int smallest = numeric_limits<int>::max();
        int secondSmallest = numeric_limits<int>::max();
        int largest = numeric_limits<int>::min();
        int secondLargest = numeric_limits<int>::min();
        
        for (auto &array: arrays) {
            if (array.size() == 0) {
                continue;
            }
            
            auto first = *begin(array);
            if (first <= smallest) {
                secondSmallest = smallest;
                smallest = first;
            } else if (first <= secondSmallest) {
                secondSmallest = first;
            }
            
            auto last = *prev(end(array));
            if (last >= largest) {
                secondLargest = largest;
                largest = last;
            } else if (last >= secondLargest) {
                secondLargest = last;
            }
        }
        
        int answer = 0;
        for (auto &array: arrays) {
            if (array.size() == 0) {
                continue;
            }
            
            auto first = *begin(array);            
            auto last = *prev(end(array));
            if (first == smallest && last == largest) {
                answer = max(answer, max(last - secondSmallest, secondLargest - first));
            // } else if (first == smallest) {
            //     answer = max(answer, max(last - secondSmallest, secondLargest - first));
            // } else if (last == largest) {     
            } else {
                answer = max(answer, max(last - smallest, largest - first));
            }            
        }
        
        return answer;
    }
};
