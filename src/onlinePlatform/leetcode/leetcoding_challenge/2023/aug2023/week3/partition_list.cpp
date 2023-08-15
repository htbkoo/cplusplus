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
    ListNode* partition(ListNode* head, int x) {
        ListNode* first = new ListNode();
        ListNode* second = new ListNode();
        
        ListNode* firstCurr = first;
        ListNode* secondCurr = second;
        
        while (head != nullptr) {
            if (head->val < x) {
                firstCurr->next = head;
                firstCurr = firstCurr->next;
            } else {
                secondCurr->next = head;
                secondCurr = secondCurr->next;
            }
            head = head->next;
        }
        
        firstCurr->next = second->next;
        secondCurr->next = nullptr;
        return first->next;
    }
};
