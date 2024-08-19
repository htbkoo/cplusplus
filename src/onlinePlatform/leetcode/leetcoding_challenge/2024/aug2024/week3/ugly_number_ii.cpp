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
    int nthUglyNumber(int n) {
        if (n == 1) {
            return 1;
        }
        
        unordered_set<long> appeared;
        priority_queue<long, vector<long>, greater<long>> pq;
        pq.push(1);
        
        vector<long> FACTORS{2, 3, 5};
        
        long num = 0;
        while (n > 0) {
            num = pq.top();                        
            pq.pop();
            
            if (appeared.count(num) > 0) {
                continue;
            }
            appeared.insert(num);
            
            n--;
            
            for (auto f: FACTORS) {
                pq.push(num * f);
            }
        }
        return num;
    }
};
