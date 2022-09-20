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
#include <string>
#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int answer = 0;
        
        for (int i = 0; i < nums1.size(); i++) {
            int currLength = 0;
            for (int j = 0; j < nums2.size(); j++) {
                if (i + j >= nums1.size()) {
                    break;
                }
                if (nums1[i + j] == nums2[j]) {
                    currLength++;
                    answer = max(answer, currLength);
                } else {
                    currLength = 0;
                }
            }
        }

        for (int j = 0; j < nums2.size(); j++) {
            int currLength = 0;
            for (int i = 0; i < nums1.size(); i++) {
                if (i + j >= nums2.size()) {
                    break;
                }
                if (nums1[i] == nums2[j + i]) {
                    currLength++;
                    answer = max(answer, currLength);
                } else {
                    currLength = 0;
                }
            }
        }
        
        return answer;
    }    
};

class WASolution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int answer = 0;
        
        for (int i = 0; i < nums1.size(); i++) {
            int j = 0;
            for (; j < nums2.size(); j++) {
                if ((i + j >= nums1.size()) || nums1[i + j] != nums2[j]) {
                    break;
                }
            }
            answer = max(answer, j);
        }
        
        return answer;
    }    
};

int main() {
    Solution soln;
    // vector<int> nums1 = {1,2,3,2,1}, nums2 = {3,2,1,4,7};
    vector<int> nums1 = {5,14,53,80,48}, nums2 = {50,47,3,80,83};
    soln.findLength(nums1, nums2);
}