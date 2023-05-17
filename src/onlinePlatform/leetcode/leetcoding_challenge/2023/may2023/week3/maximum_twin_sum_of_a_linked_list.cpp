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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        // TODO: clarify: what if head is nullptr / odd size?
        
        // naive: O(n) space + O(n) time, store into a list
        vector<int> nums;
        while (head != nullptr) {
            nums.push_back(head->val);
            head = head->next;
        }
        
        // TODO: confirm we don't need long
        int answer = nums[0] + nums[nums.size() - 1];
        for (int i = 1; ;i++) {
            int twinIdx = nums.size() - i - 1;
            if (i >= twinIdx) {
                break;
            }
            answer = max(
                answer,
                nums[i] + nums[twinIdx]
            );
        }
        
        return answer;
        
        // improved: O(n) space + O(1) time, find middle -> reverse second half -> find max sum -> restore
    }
};