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
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        vector<int> diffs;
        
        // TODO: what if nums1.size() != nums2.size()
        for (int i = 0; i < nums1.size(); ++i) {
            diffs.push_back(nums1[i] - nums2[i]);
        }
        
        sort(begin(diffs), end(diffs));
        
        long long answer = 0;
        
        for (int i = 0; i < diffs.size(); ++i) {
            int d = diffs[i];
            
            int lo = i + 1;
            int hi = diffs.size();
            
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (d + diffs[mid] > 0) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            
            answer += diffs.size() - lo;
        }
        
        return answer;
    }
};

class TLESolution2 {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> bst;
        long long answer = 0;
        
        // TODO: what if nums1.size() != nums2.size()
        for (int i = 0; i < nums1.size(); ++i) {
            int d = nums1[i] - nums2[i];
            answer += (long long) (distance(bst.upper_bound(-d), end(bst)));
            bst.insert(d);
        }
        
        return answer;
    }
};

class TLESolution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        vector<int> diffs;
        
        // TODO: what if nums1.size() != nums2.size()
        for (int i = 0; i < nums1.size(); ++i) {
            diffs.push_back(nums1[i] - nums2[i]);
        }
        
        multiset<int> bst;
        long long answer = 0;
        
        for (auto d: diffs) {
            answer += (long long) (distance(bst.upper_bound(-d), end(bst)));
            bst.insert(d);
        }
        
        return answer;
    }
};

int main() {
    Solution soln;

    vector<int> nums1 = {1,10,6,2}, nums2 = {1,4,1,5};

    cout << soln.countPairs(nums1, nums2) << endl;

    return 0;
}
