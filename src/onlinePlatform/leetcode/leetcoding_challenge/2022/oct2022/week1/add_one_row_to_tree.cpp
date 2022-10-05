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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode *newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        } else {
            return add(root, val, depth - 1);
        }
    }
    
private:
    TreeNode* add(TreeNode* root, int val, int depth) {
        if (root != nullptr) {
            if (depth == 1) {
                TreeNode* newLeft = new TreeNode(val, root->left, nullptr);
                // TreeNode newLeft = TreeNode(val, nullptr, nullptr);
                // TreeNode newLeft = TreeNode(val);
                TreeNode* newRight = new TreeNode(val, nullptr, root->right);
                // root->left = nullptr;
                root->left = newLeft;
                root->right = newRight;
            } else {
                root->left = add(root->left, val, depth - 1);
                root->right = add(root->right, val, depth - 1);
            }
        }
        return root;
    }
};