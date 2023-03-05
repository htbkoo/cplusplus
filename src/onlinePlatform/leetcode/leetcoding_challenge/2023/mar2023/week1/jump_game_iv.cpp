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
    int minJumps(vector<int>& arr) {
        unordered_map<int, set<int>> sameValuesPositions;
        for (int i = 0; i < arr.size(); i++) {
            int val = arr[i];
            sameValuesPositions[val].insert(i);
        }
        
        unordered_set<int> visited;
        
        int START = 0;
        int TARGET = arr.size() - 1;
        
        int step = 0;
        queue<int> q = queue<int>({START});
        
        while (q.size() > 0) {
            int count = q.size();
            for (int i = 0; i < count; i++) {
                int pos = q.front();
                q.pop();

                if (pos == TARGET) {
                    return step;
                }

                if (visited.count(pos) > 0) {
                    continue;
                }
                visited.insert(pos);
                
                if (pos > 0) {
                    q.push(pos - 1);
                }
                if (pos < arr.size() - 1) {
                    q.push(pos + 1);
                }

                int val = arr[pos];
                for (auto otherPos: sameValuesPositions[val]) {
                    q.push(otherPos);
                }
                sameValuesPositions.erase(val);
            }
            
            step++;
        }
        
        return arr.size() - 1;
    }
};