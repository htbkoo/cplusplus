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
        vector<double> prob(n + 1, 0.0);
        
        prob[0] = 1.0;
        
        double answer = 0.0;
        for (int i = 1; i <= n; i++) {
            
            for (int j = max(0, i - maxPts); j < min(k, i); j++) {
                prob[i] += prob[j] / (double) maxPts;
            }
            
            cout << i << " " << prob[i] << endl;

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