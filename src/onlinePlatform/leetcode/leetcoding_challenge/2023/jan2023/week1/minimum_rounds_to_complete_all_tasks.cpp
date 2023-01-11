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
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> counter;
        for (int task: tasks) {
            counter[task]++;
        }
        
        int answer = 0;
        int IMPOSSIBLE = -1;
        for (auto& [_, count]: counter) {
            if (count == 1) {
                return IMPOSSIBLE;                
            } else {
                answer += (int) ((count + 2) / 3);
            }
        }
        return answer;
    }
};
