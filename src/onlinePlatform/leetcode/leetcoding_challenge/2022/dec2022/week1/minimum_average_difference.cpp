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
    int minimumAverageDifference(vector<int>& nums) {
        long left = 0;        
        long right = sum(nums);
        
        int answer = 0;
        long minDiff = numeric_limits<long>::max();
        for (long i = 0; i < nums.size(); i++) {
            left += nums[i];
            right -= nums[i];
            
            long leftCount = i + 1;
            long rightCount = nums.size() - i - 1;
            
            long leftAvg = safeDivide(left, leftCount);
            long rightAvg = safeDivide(right, rightCount);
            
            long diff = abs(leftAvg - rightAvg);
            if (diff < minDiff) {
                answer = i;
                minDiff = diff;
            }
        }
        
        return answer;
    }
    
private:
    long sum(vector<int>& nums) {
        long s = 0;
        for (int num: nums) {
            s += (long) num;
        }
        return s;
    }
    
    long safeDivide(long numerator, long denominator) {
        if (denominator == 0) {
            // The average of 0 elements is considered to be 0.
            return 0;
        } else {
             return numerator / denominator;
        }
    }
};

class WASolution2 {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long left = 0;        
        long right = sum(nums);
        
        int answer = 0;
        long minDiff = numeric_limits<long>::max();
        for (long i = 0; i < nums.size(); i++) {
            left += nums[i];
            right -= nums[i];
            
            long leftCount = i + 1;
            long rightCount = nums.size() - i - 1;
            
            long leftAvg = safeDivide(left, leftCount);
            long rightAvg = safeDivide(right, rightCount);
            
            long diff = abs(leftAvg - rightAvg);
            if (diff < minDiff) {
                answer = i;
                minDiff = diff;
            }
        }
        
        return answer;
    }
    
private:
    long sum(vector<int>& nums) {
        long s = 0;
        for (int num: nums) {
            s += num;
        }
        return s;
    }
    
    long safeDivide(int numerator, int denominator) {
        if (denominator == 0) {
            // The average of 0 elements is considered to be 0.
            return 0;
        } else {
             return numerator / denominator;
        }
    }
};

class WASolution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long left = 0;        
        long right = sum(nums);
        
        long minDiff = numeric_limits<long>::max();
        for (long i = 0; i < nums.size(); i++) {
            left += nums[i];
            right -= nums[i];
            
            long leftCount = i + 1;
            long rightCount = nums.size() - i - 1;
            
            long leftAvg = left / leftCount;
            long rightAvg = right / rightCount;
            
            minDiff = min(minDiff, abs(leftAvg - rightAvg));
        }
        
        return minDiff;
    }
    
private:
    long sum(vector<int>& nums) {
        long s = 0;
        for (int num: nums) {
            s += num;
        }
        return s;
    }
};