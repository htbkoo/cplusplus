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
    int maxValue(int n, int index, int maxSum) {
        int lo = 0;
        int hi = maxSum;
        
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            
            long totalSum = calculateTotalSum(n, index, mid);
            
            cout << mid << " " << totalSum << endl;
            if (totalSum > maxSum) {
                hi = mid - 1;
            } else {
                lo = mid;
            }
        }
        
        return lo;
    }
    
private:
    long calculateTotalSum(int n, int index, int mid) {
        int leftLen = min(index + 1, mid);
        int rightLen = min(n - (index + 1), mid - 1);

        long leftSum = leftLen * (max(1, mid - leftLen + 1) + mid) / 2;
        long rightSum = rightLen * (max(1, (mid - 1) - rightLen + 1) + (mid - 1)) / 2;
        
        return leftSum + rightSum;
    }
};

int main() {
    Solution soln;

    cout << soln.maxValue(4, 0, 4) << endl;

    return 0;
}
