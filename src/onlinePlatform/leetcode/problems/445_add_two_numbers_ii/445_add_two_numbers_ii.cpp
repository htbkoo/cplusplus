#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr || l2 == nullptr) {
            throw invalid_argument("l1 or l2 is nullptr");
        }
        
        int l1Size = getSize(l1);
        int l2Size = getSize(l2);
                
        auto [result, carry] = add(l1, l1Size, l2, l2Size);        
        while (carry > 0) {
            result = new ListNode(carry % 10, result);
            carry /= 10;
        }        
        return result;
    }

private:
    pair<ListNode*, int> add(ListNode* l1, int l1Size, ListNode* l2, int l2Size) {
        if (l1Size == 0 || l2Size == 0) {            
            throw invalid_argument("programming error, reached the end of list");
        }
        
        if (l2Size > l1Size) {            
            // make sure l1 is longer than or has same size as l2
            return add(l2, l2Size, l1, l1Size);
        }
        
        if (l1Size > l2Size) {
            auto [tail, carry] = add(l1->next, l1Size - 1, l2, l2Size);            
            int total = carry + l1->val;
            auto *node = new ListNode(total % 10, tail);
            return pair{node, total / 10};
        } else {
            if (l1Size > 1) {
                auto [tail, carry] = add(l1->next, l1Size - 1, l2 -> next, l2Size - 1);
                int total = carry + l1->val + l2->val;
                auto *node = new ListNode(total % 10, tail);
                return pair{node, total / 10};
            } else {                
                int total = l1->val + l2->val;                
                auto *node = new ListNode(total % 10);                
                return pair{node, total / 10};
            }            
        }        
    }
    
    int getSize(ListNode* node) {
        int size = 0;
        while (node != nullptr) {
            size++;
            node = node->next;
        }
        return size;
    }    
};


/*
ListNode* nextL1 = l1 -> next, nextL2 = l2 -> next;
int nextL1Size = l1Size - 1, nextL2Size = l2Size - 1;

if (l1Size > l2Size) {
    // can hold l2 if l1 is longer
    nextL2 = l2;
    nextL2Size = l2Size;            
}

auto& [tail, carry] = add(nextL1, nextL1Size, nextL2, nextL2Size);
*/
  
/*
class WIPSolution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr || l2 == nullptr) {
            throw invalid_argument("l1 or l2 is nullptr");
        }
        
        auto [result, carry] = add(l1, l2);        
        while (carry > 0) {
            result = new ListNode(carry % 10, result);
            carry /= 10;
        }        
        return result;
        // return add(l1, l2).first;
    }

private:
    pair<ListNode*, int> add(ListNode* l1, ListNode* l2) {
        bool isL1Last = isLastNode(l1);
        bool isL2Last = isLastNode(l2);
        if (isL1Last && isL2Last) {
            int total = l1->val + l2->val;
            return pair{new ListNode(total % 10), total / 10};            
        } else {
            auto l1Next = isL1Last ? l1 : l1->next;
            auto l2Next = isL2Last ? l2 : l2->next;
            auto& [result, carry] = add(l1Next, l2Next);            
            while (carry > 0) {
                result = new ListNode(carry % 10, result);
                caryy / = 10;
            }        
            return [result;
            
//             if (isL1Last) {            
//                 auto [result]

//             } else if (isL2Last) {

//             } else 
        }
        
        
    }
    
    bool isLastNode(ListNode* node) {
        if (node == nullptr) {
            throw invalid_argument("node is nullptr");
        }
        return node->next == nullptr;
    }
};
*/