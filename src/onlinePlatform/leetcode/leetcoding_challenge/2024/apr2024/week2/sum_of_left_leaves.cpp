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
    int sumOfLeftLeaves(TreeNode* root) {
        return getSum(root, false);
    }

private:
    int getSum(TreeNode* root, bool isLeft) {
        if (root == nullptr) {
            return 0;
        }

        bool isLeaf = root->left == nullptr && root->right == nullptr;
        if (isLeaf) {
            if (isLeft) {
                return root->val;
            } else {
                return 0;
            }
        }

        return getSum(root->left, true) + getSum(root->right, false);
    }
};
