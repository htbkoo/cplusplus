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
    double new21Game(int n, int k, int maxPts) {
        if (k == 0) {
            return 1.0;
        }
        
        vector<double> prob(n + 1, 0.0);
        prob[0] = 1.0;

        queue<pair<int, double>> q({pair{0, prob[0] / (double) maxPts}});
        
        double answer = 0.0;
        double curr = prob[0] / (double) maxPts;
        for (int i = 1; i <= n; i++) {
            if ((q.size() > 0) && (i > (q.front().first + maxPts))) {
                auto [idx, p] = q.front();
                curr -= p;
                q.pop();
            }
            
            prob[i] = curr;
            
            if (i >= k) {
                answer += prob[i];
            } else {
                double newP = prob[i] / (double) maxPts;
                curr += newP;
                q.push(pair{i, newP});
            }
        }
        
        return answer;
    }
};

// DP, time = O(n*maxPts)
class TLESolution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0) {
            return 1.0;
        }
        
        vector<double> prob(n + 1, 0.0);
        
        prob[0] = 1.0;
        
        double answer = 0.0;
        for (int i = 1; i <= n; i++) {
            
            for (int j = max(0, i - maxPts); j < min(k, i); j++) {
                prob[i] += prob[j] / (double) maxPts;
            }
            
            if (i >= k) {
                answer += prob[i];
            }
        }
        
        return answer;
    }
};

int main() {
    int n, k, maxPts;

    Solution soln;

    cout << soln.new21Game(n = 6, k = 1, maxPts = 10) << endl;

    return 0;
}