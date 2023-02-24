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
        long maxNum = numeric_limits<long>::min();
        long minNum = numeric_limits<long>::max();
        set<pair<long, long>> longs;
        for (int num: nums) {
            int finalNum = num;
            while (finalNum % 2 == 0) {
                finalNum /= 2;
            }

            maxNum = max(maxNum, (long) finalNum);
            minNum = min(minNum, (long) finalNum);

            longs.insert(pair{finalNum, num});
        }
        
        long answer = maxNum - minNum;
        
cout << "a: " << answer << " " << minNum << " " << maxNum << endl;

        min_priority_queue<pair<long, long>> pq(longs.begin(), longs.end());
        
        while (true) {
            auto [minNum, minNumRange] = pq.top();
            pq.pop();

cout << "b: " << minNum << " " << minNumRange << endl;

            if (minNum % 2 == 0 && minNum >= minNumRange) {
                break;
            }

            if (minNum > numeric_limits<int>::max() / 2) {
                break;
            }

            long newNum = minNum * 2;
cout << "d: "<< minNum << " " << newNum << " " << maxNum << endl;
            maxNum = max(maxNum, newNum);

            pq.push(pair{newNum, minNumRange});
            
            long newDiff = maxNum - pq.top().first;

cout << "c: " << newNum << " " << maxNum << " " << pq.top().first << " " << newDiff << " " << answer << endl;

            if (newDiff > answer) {
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
    vector<int> nums = {610,778,846,733,395}; // 236
    // vector<int> nums = {900,241,842,374,758,39,687,242,912};
    // vector<int> nums = {399,908,648,357,693,502,331,649,596,698};
    cout << soln.minimumDeviation(nums) << endl;

    return 0;
}