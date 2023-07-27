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
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(), batteries.end(), greater<int>());
        
        unordered_map<long long, int> counts;        
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        if (n > batteries.size()) {
            return 0;
        }
        
        for (int i = 0; i < n; ++i) {
            auto battery = batteries[i];
            if (counts.count(battery) == 0) {
                pq.push(battery);
            }
            counts[battery]++;
        }
        
        long long curr = 0;
        for (int i = n; i < batteries.size(); ++i) {
            curr += batteries[i];
            
            while (true) {
                auto smallest = pq.top();
                
                if (curr < counts[smallest]) {
                    break;
                }

                pq.pop();
                
                long long bound = pq.size() > 0
                    ? pq.top()
                    : numeric_limits<long long>::max();
                
                long long canReach = smallest + curr / counts[smallest];
                
                long long become = min(bound, canReach);
                
                long long diff = become - smallest;
                
                if (counts.count(become) == 0) {
                    pq.push(become);
                }
                
                curr -= diff * counts[smallest];
                counts[become] += counts[smallest];
                counts[smallest] = 0;
            }            
        }
        
        return pq.top();
    }
};

int main() {
    Solution soln;

    // int n = 2;
    // vector<int> batteries = {3,3,3};
    int n = 3;
    vector<int> batteries = {7,5,3,4,1,3,7,1,4,2};
    // int n = 3;
    // vector<int> batteries = {7,7,5,4,4};

    cout << soln.maxRunTime(n, batteries) << endl;

    return 0;
}