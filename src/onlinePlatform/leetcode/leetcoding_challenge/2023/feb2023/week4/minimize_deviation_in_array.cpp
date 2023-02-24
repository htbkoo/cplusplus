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


template <typename T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        unordered_set<long> longs;
        for (int num: nums) {
            while (num % 2 == 0) {
                num /= 2;
            }
            longs.insert(num);
        }
        
        long maxNum = *max_element(longs.begin(), longs.end());
        long answer = maxNum - *min_element(longs.begin(), longs.end());
        
cout << answer << endl;

        min_priority_queue<long> pq(longs.begin(), longs.end());
        
        while (true) {
            long minNum = pq.top();
            pq.pop();

cout << minNum << endl;

            if (minNum % 2 == 0) {
                break;
            }

            if (minNum > numeric_limits<int>::max() / 2) {
                break;
            }

            long newNum = minNum * 2;
            maxNum = max(maxNum, newNum);

            pq.push(newNum);
            
            long newDiff = maxNum - pq.top();
            if (newDiff >= answer) {
                break;
            } else {
                answer = newDiff;
            }
        }
 
        return answer;
    }
};

int main() {
    Solution soln;

    // vector<int> nums = {2,8,10};
    vector<int> nums = {399,908,648,357,693,502,331,649,596,698};
    cout << soln.minimumDeviation(nums) << endl;

    return 0;
}