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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode dummy(0, head);
        head = &dummy;
        vector<ListNode*> stack{head};
        head = head->next;
        while (head != nullptr) {
            bool removed = false;

            int curr = head->val;
            if (curr == 0) {
                removed = true;
            } else {
                for (int i = stack.size() - 1; i >= 1; --i) {
                    curr += stack[i]->val;
                    if (curr == 0) {
                        const auto count = stack.size();
                        for (int j = i; j < count; ++j) {
                            stack.pop_back();
                        }
                        removed = true;
                        break;
                    }
                }
            }

            if (!removed) {
                stack.back()->next = head;
                stack.push_back(head);
            } else {
                stack.back()->next = head -> next;
            }

            head = head->next;
        }

        return dummy.next;
    }
};

class WASolution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode dummy(0, head);
        head = &dummy;
        vector<ListNode*> stack{head};
        head = head->next;
        while (head != nullptr) {
            bool removed = false;

            int curr = head->val;
            for (int i = stack.size() - 1; i >= 1; --i) {
                curr += stack[i]->val;
                if (curr == 0) {
                    const auto count = stack.size();
                    for (int j = i; j < count; ++j) {
                        stack.pop_back();
                    }
                    removed = true;
                    break;
                }
            }

            if (!removed) {
                stack.back()->next = head;
                stack.push_back(head);
            } else {
                stack.back()->next = head -> next;
            }

            head = head->next;
        }

        return dummy.next;
    }
};

ListNode* asListNode(const vector<int>& v) {
    auto* dummy = new ListNode();
    ListNode* curr = dummy;

    for (auto i: v) {
        curr->next = new ListNode(i);
        curr = curr->next;
    }

    const auto result = dummy->next;
    delete dummy;
    return result;
}

int main () {
    Solution soln;

    const vector v{1,2,-3,3,1};
    ListNode* head = asListNode(v);

    // cout << soln.removeZeroSumSublists(head) << endl;

    const auto result = soln.removeZeroSumSublists(head);

    delete head;
    delete result;

    return 0;
}