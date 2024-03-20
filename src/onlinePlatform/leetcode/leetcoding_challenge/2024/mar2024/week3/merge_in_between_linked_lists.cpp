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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* curr = list1;
        ListNode* prev;
        // TODO: validate input, e.g. b > a
        for (int i = 0; i <= b; ++i) {
            if (i == a - 1) {
                prev = curr;
            }
            // TODO: what if a > len(list1) or b >= len(list1)?
            curr = curr->next;
        }

        prev->next = list2;

        auto tail2 = getTail(list2);
        tail2->next = curr;

        return list1;
    }

private:
    ListNode* getTail(ListNode* list) {
        // TODO: what if list is empty?
        while (list && list->next) {
            list = list->next;
        }
        return list;
    }
};