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

#include <random>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {                
        return asBST(head);
    }
    
private:   
    TreeNode* asBST(ListNode* begin, ListNode* end=nullptr) {
        if (begin == nullptr || begin == end) {
            return nullptr;
        }
        
        if (begin->next == end) {
            return new TreeNode(begin->val);
        }
        
        ListNode* mid = findMid(begin, end);
        
        TreeNode* left = asBST(begin, mid);
        TreeNode* right = mid == nullptr ? nullptr : asBST(mid->next, end);
        TreeNode* BST = new TreeNode(mid->val, left, right);
        return BST;
    }
    
    
    ListNode* findMid(ListNode* begin, ListNode* end=nullptr) {
        ListNode* fast = begin;
        ListNode* slow = begin;
        
        while (fast != end && fast->next != end) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow;
    }
};

class FirstSolution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v = asVector(head);
        
        return asBST(v, 0, v.size() - 1);
    }
    
private:
    vector<int> asVector(ListNode* head) {        
        vector<int> v;
        while (head != nullptr) {
            v.push_back(head->val);
            head = head->next;
        }        
        return v;
    }
    
    TreeNode* asBST(vector<int> v, int lo, int hi) {
        if (lo > hi) {
            return nullptr;
        }
        
        int mid = lo + (hi - lo) / 2;
        
        TreeNode* left = asBST(v, lo, mid - 1);
        TreeNode* right = asBST(v, mid + 1, hi);
        TreeNode* BST = new TreeNode(v[mid], left, right);
        return BST;
    }
};