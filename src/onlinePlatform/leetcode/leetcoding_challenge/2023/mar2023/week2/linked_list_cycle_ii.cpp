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
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *NO_CYCLE = nullptr;
        
        ListNode *fast = head, *slow = head;
        
        do {
            if (fast == nullptr || fast->next == nullptr) {
                return NO_CYCLE;
            }
            fast = fast->next->next;
            slow = slow->next;
        } while (fast != slow);
        
        while (head != fast) {
            head = head -> next;
            fast = fast -> next;
        } 
        
        return head;
    }
};