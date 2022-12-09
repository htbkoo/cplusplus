#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int left = 0;
        int right = 0;
        bool isDup = false;
        while (right < arr.size() - 1) {
            isDup = false;
            if (arr[left] == 0) {
                isDup = true;
                right++;
            }
            left++;
            right++;
        }
        
        while (right > arr.size() - 1) {
            right--;
            left--;
        }
        
        // right = min(right, arr.size() - 1);
        
        while (right >= 0) {
            if (isDup && right > left && arr[left] == 0) {
                if (right <= arr.size() - 1) {
                    arr[right] = 0;
                }
                right--;
            }
            isDup = true;
            
            arr[right] = arr[left];
            left--;
            right--;
        }
    }
};

class WIPSolution {
public:
    void duplicateZeros(vector<int>& arr) {
        int left = 0;
        int right = 0;
        
        while (right < arr.size() - 1) {
            if (arr[left] == 0) {
                right++;
            }
            left++;
            right++;
        }
        
        bool isLast = true;
        
        while (left >= 0 && right >= 0) {
            if (right > left && !isLast && arr[left] == 0) {
                if (right <= arr.size() - 1) {
                    arr[right] = 0;
                }
                right--;
            }
            isLast = false;
            
            arr[right] = arr[left];
            left--;
            right--;
        }
    }
};


class WASolution3 {
public:
    void duplicateZeros(vector<int>& arr) {
        int left = 0;
        int right = 0;
        
        while (right < arr.size() - 1) {
            if (arr[left] == 0) {
                right++;
            }
            left++;
            right++;
        }
        
        // while (right > arr.size() - 1) {
        //     right--;
        //     left--;
        // }
        
        // right = min(right, arr.size() - 1);
        
        while (right >= 0) {
            if (right > left && arr[left] == 0) {
                if (right <= arr.size() - 1) {
                    arr[right] = 0;
                }
                right--;
            }
            arr[right] = arr[left];
            left--;
            right--;
        }
    }
};

class WASolution2 {
public:
    void duplicateZeros(vector<int>& arr) {
        int left = 0;
        int right = 0;
        
        while (right < arr.size() - 1) {
            if (arr[left] == 0) {
                right++;
            }
            left++;
            right++;
        }
        
        while (right > arr.size() - 1) {
            right--;
            left--;
        }
        
        // right = min(right, arr.size() - 1);
        
        while (right >= 0) {
            if (right > left && arr[left] == 0) {
                arr[right] = 0;
                right--;
            }
            arr[right] = arr[left];
            left--;
            right--;
        }
    }
};

class WASolution {
public:
    void duplicateZeros(vector<int>& arr) {
        int numZero = 0;
        
        for (int num: arr) {
            if (num == 0) {
                numZero++;
            }
        }
            
        int left = arr.size() - 1 - numZero;
        int right = arr.size() - 1;
        
        while (right >= 0) {
            if (arr[left] == 0) {
                arr[right] = 0;
                right--;
            }
            arr[right] = arr[left];
            left--;
            right--;
        }
    }
};

int main() {
    vector<int> arr = {9,9,9,4,8,0,0,3,7,2,0,0,0,0,9,1,0,0,1,1,0,5,6,3,1,6,0,0,2,3,4,7,0,3,9,3,6,5,8,9,1,1,3,2,0,0,7,3,3,0,5,7,0,8,1,9,6,3,0,8,8,8,8,0,0,5,0,0,0,3,7,7,7,7,5,1,0,0,8,0,0};
    Solution().duplicateZeros(arr);    

    arr = {0};
    Solution().duplicateZeros(arr);    
    
    arr = {0,0};
    Solution().duplicateZeros(arr);    
    
    arr = {1,0,2,3,0,4,5,0};
    Solution().duplicateZeros(arr);    

    arr = {1,2,3};
    Solution().duplicateZeros(arr);    
    
    arr = {1,0,2,3,0,4,5};
    Solution().duplicateZeros(arr);    

    cout << endl;
}