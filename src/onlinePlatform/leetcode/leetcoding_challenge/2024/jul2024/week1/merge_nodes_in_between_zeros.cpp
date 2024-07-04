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
    ListNode* mergeNodes(ListNode* head) {
        if (head == nullptr) {
            return head;
        }

        // TODO:
        //  1. validate the first node is 0
        //  2. assume we can mutate the head list
        //  3. what if consecutive 0?

        auto currNode = head->next;
        int currSum = 0;
        ListNode* dummy = new ListNode(0);
        auto dummyCurr = dummy;

        while (currNode != nullptr) {
            if (currNode->val == 0) {
                dummyCurr->next = new ListNode(currSum);
                dummyCurr = dummyCurr->next;
                currSum = 0;
            } else {
                currSum += currNode->val;
            }
            currNode = currNode->next;
        }

        return dummy->next;
    }
};
