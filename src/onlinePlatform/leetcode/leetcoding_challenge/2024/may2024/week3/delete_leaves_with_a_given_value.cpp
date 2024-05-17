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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root == nullptr) {
            return root;
        }

        removeLeafNodes(root->left, target);
        removeLeafNodes(root->right, target);

        if (shouldRemove(root->left, target)) {
            root->left = nullptr;
        }

        if (shouldRemove(root->right, target)) {
            root->right = nullptr;
        }

        if (shouldRemove(root, target)) {
            // TODO: confirm this
            return nullptr;
        }

        return root;
    }

private:
    bool shouldRemove(TreeNode* root, int target) {
        if (root == nullptr) {
            return false;
        }

        bool isLeaf = root->left == nullptr && root->right == nullptr;

        return isLeaf && root->val == target;
    }

};
