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

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return head;
        }
        
        Node* curr;
        curr = head;
        while (curr != nullptr) {
            Node* cloneNode = new Node(curr->val);
            cloneNode->next = curr->next;
            curr->next = cloneNode;
            
            curr = curr->next->next;
        }        
        Node* answer = head->next;
        
        curr = head;
        while (curr != nullptr) {
            if (curr->random != nullptr) {
                curr->next->random = curr->random->next;
            }
            
            curr = curr->next->next;
        }
        
        curr = head;
        while (curr != nullptr) {
            Node* nextNode = curr->next;
            curr->next = curr->next->next;
            
            if (curr->next == nullptr) {
                nextNode->next = nullptr;
            } else {
                nextNode->next = curr->next->next;
            }
            
            curr = curr->next;
        }
        
        return answer;
    }
};