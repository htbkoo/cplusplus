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
    long long minCost(vector<int>& nums, vector<int>& cost) {
        map<int, long long> costsAtNums;
        
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            int c = cost[i];
            costsAtNums[num] += c;
        }
        
        set<int> numsSet = set<int>(nums.begin(), nums.end());
        vector<int> sortedNums = vector<int>(numsSet.begin(), numsSet.end());
        sort(sortedNums.begin(), sortedNums.end());
        
        int minNum = sortedNums[0];
        long long totalCost = 0;
        long long leftCost = costsAtNums[minNum];
        long long rightCost = 0;
        for (int i = 1; i < sortedNums.size(); ++i) {
            int num = sortedNums[i];
            long long c = costsAtNums[num];
            
            totalCost += (long long)(num - minNum) * c;
            rightCost += c;
        }

        long long answer = totalCost;

        for (int i = 1; i < sortedNums.size(); ++i) {
            long long numDiff = sortedNums[i] - sortedNums[i - 1];
            
            totalCost += numDiff * leftCost;
            
            int num = sortedNums[i];
            totalCost -= numDiff * rightCost;
            rightCost -= costsAtNums[num];
            
            answer = min(answer, totalCost);
            
            leftCost += costsAtNums[num];
        }
        
        return answer;
    }
};

class WASolution2 {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        map<int, long long> costsAtNums;
        
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            int c = cost[i];
            costsAtNums[num] += c;
        }
        
        vector<int> sortedNums = vector<int>(nums.begin(), nums.end());
        sort(sortedNums.begin(), sortedNums.end());
        
        int minNum = sortedNums[0];
        long long totalCost = 0;
        long long leftCost = costsAtNums[minNum];
        long long rightCost = 0;
        for (int i = 1; i < sortedNums.size(); ++i) {
            long long num = sortedNums[i];
            long long c = costsAtNums[num];
            
            totalCost += (long long) (num - minNum) * c;
            rightCost += c;
        }

        long long answer = totalCost;

        for (int i = 1; i < sortedNums.size(); ++i) {
            long long numDiff = sortedNums[i] - sortedNums[i - 1];
            
            totalCost += numDiff * leftCost;            
            totalCost -= numDiff * rightCost;

            answer = min(answer, totalCost);

            int num = sortedNums[i];
            leftCost += costsAtNums[num];
            rightCost -= costsAtNums[num];            
        }
        
        return answer;
    }
};

class WASolution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        map<int, long long> costsAtNums;
        
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            int c = cost[i];
            costsAtNums[num] += c;
        }
        
        vector<int> sortedNums = vector<int>(nums.begin(), nums.end());
        sort(sortedNums.begin(), sortedNums.end());
        
        int minNum = sortedNums[0];
        long long totalCost = 0;
        long long leftCost = costsAtNums[minNum];
        long long rightCost = 0;
        for (int i = 1; i < sortedNums.size(); ++i) {
            int num = sortedNums[i];
            long long c = costsAtNums[num];
            
            totalCost += (long long)(num - minNum) * c;
            rightCost += c;
        }

        long long answer = totalCost;

        for (int i = 1; i < sortedNums.size(); ++i) {
            long long numDiff = sortedNums[i] - sortedNums[i - 1];
            
            totalCost += numDiff * leftCost;
            
            int num = sortedNums[i];
            totalCost -= numDiff * rightCost;
            rightCost -= costsAtNums[num];
            
            answer = min(answer, totalCost);
            
            leftCost += costsAtNums[num];
        }
        
        return answer;
    }
};

/*
class WIPSolution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        map<int, long long> costsAtNums;
        
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            int c = cost[i];
            costsAtNums[num] += c;
        }
        
        vector<int> sortedNums = vector<int>(nums.begin(), nums.end());
        sort(sortedNums.begin(), sortedNums.end());
        
        
        bool first = true;
        int minNum = costsAtNums.begin()->first;
        long long totalCost = 0;
        for (auto const& it: costsAtNums) {
            if (first) {
                first = false;
                continue;
            }
            
            int num = it->first;
            long long c = it->second;
            
            totalCost += (num - minNum) * c;
        }

        first = true;
        long long prevCost = 0;
        long long answer = totalCost;
        for (auto const& it: costsAtNums) {
            if (first) {
                first = false;
                continue;
            }
            
            int num = it->first;
            long long c = it->second;
            
            totalCost += (num - minNum) * c;
        }
        
        
        
        return answer;
    }
};
*/

int main() {
    Solution soln;

    vector<int> nums = {1,3,5,2}, cost = {2,3,1,14};

    cout << soln.minCost(nums, cost) << endl;

    return 0;
}