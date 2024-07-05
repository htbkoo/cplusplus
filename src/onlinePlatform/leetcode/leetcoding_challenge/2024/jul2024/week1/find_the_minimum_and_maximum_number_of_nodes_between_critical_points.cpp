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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return {-1, -1};
        }

        int minDist = numeric_limits<int>::max();

        int first = -1;
        int prev = -1;
        int last = -1;
        auto prevVal = head->val;
        auto curr = head->next;

        int pos = 1;
        while (curr != nullptr && curr->next != nullptr) {
            auto val = curr->val;
            auto nextVal = curr->next->val;
            bool isLocalMaxima = val > prevVal && val > nextVal;
            bool isLocalMinima = val < prevVal && val < nextVal;
            bool isCriticalPoint = isLocalMaxima || isLocalMinima;
            if (isCriticalPoint) {
                if (first == -1) {
                    first = pos;
                }
                last = pos;

                if (prev != -1) {
                    minDist = min(minDist, pos - prev);
                }
                prev = pos;
            }

            prevVal = val;
            curr = curr->next;
            pos++;
        }

        if (last > first) {
            return {minDist, last - first};
        } else {
            return {-1, -1};
        }

    }
};
