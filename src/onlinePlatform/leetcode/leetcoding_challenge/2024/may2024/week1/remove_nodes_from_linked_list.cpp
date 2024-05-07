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
    ListNode* removeNodes(ListNode* head) {
        vector<ListNode*> stack;

        while (head != nullptr) {
            while (stack.size() > 0 && head->val > stack.back()->val) {
                stack.pop_back();
            }
            stack.push_back(head);
            head = head->next;
        }

        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        for (auto node: stack) {
            curr->next = node;
            curr = curr->next;
        }

        ListNode* answer = dummy->next;
        delete dummy;
        return answer;
    }
};
