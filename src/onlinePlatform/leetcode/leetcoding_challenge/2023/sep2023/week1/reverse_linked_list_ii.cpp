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
    ListNode* reverseBetween(ListNode* head, int left, int right) {        
        // TODO: clarify: what if left or right is invalid (non-positive / > length); left > right
        if (left >= right) {
            return head;
        }

        ListNode* dummy = new ListNode(0, head);
        
        int i = 1;
        
        ListNode* curr = dummy;

        while (curr != nullptr) {
            if (i == left) {
                ListNode* newTail = curr->next;
                auto [tail, afterTail] = reverse(curr->next, right - left);
                curr->next = tail;
                newTail->next = afterTail;
                
                break;
            }            
            curr = curr->next;
            i++;
        }
        
        return dummy->next;
    }
    
private:
    pair<ListNode*, ListNode*> reverse(ListNode* node, int count) {
        ListNode* prev;
        
        while (count >= 0 && node != nullptr) {
            ListNode* nextNode = node->next;
            node->next = prev;
            prev = node;
            node = nextNode;
            
            count--;
        }
        
        return pair{prev, node};
    }
};