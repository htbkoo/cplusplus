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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return;
        }

        auto fast = head;
        auto slow = head;

        while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        auto midPrev = slow;

        auto tail = reverseList(midPrev);

        while (head != tail && head != nullptr && tail != nullptr) {
            auto headNext = head->next;
            auto tailNext = tail->next;

            head->next = tail;
            tail->next = headNext;

            head = headNext;
            tail = tailNext;
        }

        return;
    }

private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = head;
        head = head->next;
        prev->next = nullptr;

        while (head) {
            auto next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }
};

class FirstSolution {
public:
    void reorderList(ListNode* head) {
        auto curr = head;

        vector<ListNode*> arr;

        while (curr != nullptr) {
            arr.push_back(curr);
            curr = curr->next;
        }

        ListNode* dummy = new ListNode();
        curr = dummy;
        int lo = 0;
        int hi = arr.size() - 1;

        while (lo <= hi) {
            curr->next = arr[lo];
            curr = curr->next;
            lo++;
            if (hi < lo) {
                break;
            }

            curr->next = arr[hi];
            curr = curr->next;
            hi--;
        }

        curr->next = nullptr;

        return;
    }
};