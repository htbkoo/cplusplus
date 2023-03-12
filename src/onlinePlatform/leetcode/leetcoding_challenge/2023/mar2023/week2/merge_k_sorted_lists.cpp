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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode();
        
        auto cmp = [](ListNode* a, ListNode* b) {return a->val > b->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for (auto head: lists) {
            if (head != nullptr) {
                pq.push(head);
            }
        }
        
        ListNode* curr = dummy;
        while (pq.size() > 0) {
            auto node = pq.top();
            pq.pop();
            
            curr->next = node;
            curr = curr->next;
            
            node = node->next;
            if (node != nullptr) {
                pq.push(node);
            }
        }
        
        return dummy->next;
    }
};


class FirstSolution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode();
        
        auto cmp = [](pair<int, ListNode*>& a, pair<int, ListNode*>& b) {return a.first > b.first;};
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, decltype(cmp)> pq(cmp);
        for (auto head: lists) {
            if (head != nullptr) {
                pq.push(pair{head->val, head});
            }
        }
        
        ListNode* curr = dummy;
        while (pq.size() > 0) {
            auto [_, node] = pq.top();
            pq.pop();
            
            curr->next = node;
            curr = curr->next;
            
            node = node->next;
            if (node != nullptr) {
                // pq.push(pair{node->val, node});
                pq.push(pair<int, ListNode*>{node->val, node});
            }
        }
        
        return dummy->next;
    }
};
