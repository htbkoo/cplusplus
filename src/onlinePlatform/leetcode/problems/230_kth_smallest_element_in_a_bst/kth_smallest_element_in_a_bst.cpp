#include <algorithm>
#include <vector>
#include <set>
#include <limits>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <sstream>
#include <queue>
#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
    int kthSmallest(TreeNode* root, int k) {
        remainK = k;
        return preorder(root);
    }
    
private:
    int remainK;
    int NO_ANSWER = -1;

    int preorder(TreeNode* root) {
        if (root == nullptr) {
            return NO_ANSWER;
        }
        
        int leftResult = preorder(root->left);
        if (leftResult != NO_ANSWER) {
            return leftResult;
        }
            
        remainK--;
        if (remainK == 0) {
            return root->val;
        }
        
        int rightResult = preorder(root->right);
        if (rightResult != NO_ANSWER) {
            return rightResult;
        }
        
        return NO_ANSWER;
    }

};