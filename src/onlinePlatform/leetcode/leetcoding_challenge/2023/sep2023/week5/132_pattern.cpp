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
    bool find132pattern(vector<int>& nums) {
        vector<int> largerStack;
        vector<int> largestSmallerOnRight(nums.size(), numeric_limits<int>::min());
        
        for (int i = nums.size() - 1; i >= 0; --i) {
            int num = nums[i];
            while (largerStack.size() > 0 && num > nums[largerStack.back()]) {
                int idx = largerStack.back();
                largerStack.pop_back();
                largestSmallerOnRight[i] = max(largestSmallerOnRight[i], nums[idx]); 
            } 
            largerStack.push_back(i);
        }
        
        int smallest = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            smallest = min(smallest, num);
            if (smallest < largestSmallerOnRight[i]) {
                return true;
            }
        }
        
        return false;
    }
};


class WASolution2 {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int> smaller(nums.size(), numeric_limits<int>::max());
        vector<int> larger(nums.size(), numeric_limits<int>::min());
        vector<int> smallerStack;
        vector<int> largerStack;
        
        for (int i = nums.size() - 1; i >= 0; --i) {
            int num = nums[i];
            while (smallerStack.size() > 0 && num < nums[smallerStack.back()]) {
                int idx = smallerStack.back();
                smallerStack.pop_back();
                smaller[idx] = i;
                if (smaller[idx] < larger[idx]) {
                    return true;
                }
            } 
            while (largerStack.size() > 0 && num > nums[largerStack.back()]) {
                int idx = largerStack.back();
                largerStack.pop_back();
                larger[idx] = i;
                if (smaller[idx] < larger[idx]) {
                    return true;
                }
            } 

            smallerStack.push_back(i);
            largerStack.push_back(i);
        }
        
        return false;
    }
};

class WASolution {
public:
    bool find132pattern(vector<int>& nums) {
        int two = nums.back();
        int three = numeric_limits<int>::min();
        
        for (int i = nums.size() - 1; i >= 0; --i) {
            int num = nums[i];
            if (num < two && num < three) {
                return true;
            }            
            if (num > two) {
                two = max(two, three);
                three = max(three, num);
            }
            if (three == numeric_limits<int>::min()) {
                two = min(two, num);
            }
        }
        
        return false;
    }
};