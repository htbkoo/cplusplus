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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        if (head == nullptr) {
            return vector<ListNode*>(k, nullptr);
        }
        
        int listSize = 0;
        ListNode* curr;
        curr = head;
        while (curr != nullptr) {
            curr = curr->next;
            listSize++;
        }
        
        vector<ListNode*> answer = {head};
        curr = head;
        int eachPartitionSize = listSize / k;
        int remainPartitionSize = eachPartitionSize + (answer.size() <= (listSize % k) ? 1 : 0);
        while (curr != nullptr) {
            remainPartitionSize--;
            ListNode* nextNode = curr->next;
            
            if (remainPartitionSize == 0) {
                curr->next = nullptr;
                if (answer.size() < k) {                 
                    answer.push_back(nextNode);   
                }
                remainPartitionSize = eachPartitionSize + (answer.size() <= (listSize % k) ? 1 : 0);
            }
            curr = nextNode;
        }
        
        while (answer.size() < k) {
            answer.push_back(nullptr);
        }
        
        return answer;
    }
};