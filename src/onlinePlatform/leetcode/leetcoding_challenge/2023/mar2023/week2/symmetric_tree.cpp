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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            // TOOD: confirm this
            return true;
        }
        
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push(pair{root->left, root->right});

        while (q.size() > 0) {
            auto [left, right] = q.front();
            q.pop();
            
            if (left == nullptr && right == nullptr) {
                continue;
            }

            if (left == nullptr || right == nullptr) {
                return false;
            }
            
            if (left->val != right->val) {
                return false;
            }
            
            q.push(pair{left->left, right->right});
            q.push(pair{left->right, right->left});
        }

        return true;
    }
};

class RecursiveSolution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            // TOOD: confirm this
            return true;
        }

        return isChildrenSymmetric(root->left, root->right);
    }

private:
    bool isChildrenSymmetric(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return true;
        }
        
        if (left == nullptr || right == nullptr) {
            return false;
        }
        
        if (left->val != right->val) {
            return false;
        }
        
        return isChildrenSymmetric(left->left, right->right) && isChildrenSymmetric(left->right, right->left);
    }
};
