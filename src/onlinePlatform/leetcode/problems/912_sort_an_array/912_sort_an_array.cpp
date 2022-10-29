#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        nums = vector<int>(nums);
        
        heapify(nums);
        
        int n = nums.size();        
        while (n > 0) {
            swap(nums, 0, n - 1);
            n--;
            
            pushDown(nums, 0, n);
        }
        
        return nums;
    }
    
private:        
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    void heapify(vector<int>& nums) {
        for (int i = nums.size() - 1; i >= 0; i--) {
            pushDown(nums, i, nums.size());
        }
    }
    
    void pushDown(vector<int>& nums, int i, int n) {
        if (i * 2 + 1 >= n) {
            return;
        }
        
        int betterIdx = getBetterIdx(nums, i, n);
        if (nums[i] >= nums[betterIdx]) {
            return;
        }
        
        swap(nums, i, betterIdx);
        pushDown(nums, betterIdx, n);
    }
    
    int getBetterIdx(vector<int>& nums, int i, int n) {
        if (i * 2 + 2 >= n) {
            return i * 2 + 1;
        }
        
        if (nums[i * 2 + 1] >= nums[i * 2 + 2]) {
            return i * 2 + 1;
        }
        
        return i * 2 + 2;
    }
    
};