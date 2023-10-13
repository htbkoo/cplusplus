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

// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation
class MountainArray {
  public:
    int get(int index);
    int length();
};

const int UNKNOWN = -1;


/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */


class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {        
        m = &mountainArr;
        arr = vector<int>(mountainArr.length(), UNKNOWN);
        
        int size = mountainArr.length();
        
        // 0. find idx of tip
        int lo, hi;
        
        lo = 0;
        hi = size - 1;
        
        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;

            if (mid == 0) {
                break;
            } else {
                int left = get(mid - 1);
                int right = get(mid);
                if (left < right) {
                    lo = mid;
                } else if (left > right) {
                    hi = mid;
                } else {
                    throw invalid_argument("there are consecutive equal elements");
                }
            }
        }  
        
        int tipIdx;
        int left = get(lo);
        int right = get(hi);
        if (left < right) {
            tipIdx = hi;
        } else {
            tipIdx = lo;
        }
        
        // 1. search first half
        lo = 0;
        hi = tipIdx;
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (get(mid) == target) {
                return mid;
            } else if (get(mid) > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        if (get(lo) == target) {
            return lo;
        }
         
        // 2. search second half
        lo = tipIdx;
        hi = size - 1;
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (get(mid) == target) {
                return mid;
            } else if (get(mid) > target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        if (get(lo) == target) {
            return lo;
        }

        return -1;
    }
    
private:
    MountainArray* m;
    vector<int> arr;
    
    int get(int idx) {
        if (arr[idx] == UNKNOWN) {
            arr[idx] = m->get(idx);
        }
        return arr[idx];
    }
};

class WASolution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {        
        m = &mountainArr;
        vector<int> arr(mountainArr.length(), UNKNOWN);
        
        int size = mountainArr.length();
        
        // 0. find idx of tip
        int lo, hi;
        
        lo = 0;
        hi = size - 1;
        
        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            
            if (mid == 0) {
                break;
            } else {
                int left = get(mid - 1);
                int right = get(mid);
                if (left < right) {
                    lo = left;
                } else if (left > right) {
                    hi = right;
                } else {
                    throw invalid_argument("there are consecutive equal elements");
                }
                
            }
            
            
        }  
        
        int tipIdx;
        int left = get(lo);
        int right = get(hi);
        if (left < right) {
            tipIdx = hi;
        } else if (left > right) {
            tipIdx = lo;
        } else {
            throw invalid_argument("there are consecutive equal elements");
        }
        
        // 1. search first half
        lo = 0;
        hi = tipIdx;
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (get(mid) == target) {
                return mid;
            } else if (get(mid) > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        if (get(lo) == target) {
            return lo;
        }
         
        // 2. search second half
        lo = tipIdx;
        hi = size - 1;
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (get(mid) == target) {
                return mid;
            } else if (get(mid) > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        if (get(lo) == target) {
            return lo;
        }

        return -1;
    }
    
private:
    MountainArray* m;
    vector<int> arr;
    
    int get(int idx) {
        if (arr[idx] == UNKNOWN) {
            arr[idx] = m->get(idx);
        }
        return arr[idx];
    }
};