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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        for (int i = 0; i < k; i++) {
            // TODO: validate input, e.g. what if fast is nullptr?
            fast = fast->next;
        }
        
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode* first = dummy;
        for (int i = 0; i < k - 1; i++) {
            first = first->next;
        }
        
        int temp = slow->next->val;
        slow->next->val = first->next->val;
        first->next->val = temp;
        
//         ListNode* temp = slow->next;
//         slow->next = first->next;
//         first->next = temp;
        
        return dummy->next;
    }
};