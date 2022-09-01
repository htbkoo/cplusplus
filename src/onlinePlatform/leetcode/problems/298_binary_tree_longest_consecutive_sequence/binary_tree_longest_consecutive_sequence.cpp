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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int answer = 0;

    int longestConsecutive(TreeNode* root) {        
        if (!root) {
            return 0;
        }

        dfs(root);

        return answer;
    }

    int dfs(TreeNode* root) {
        int length = 1;
        if (root->left) {
            auto left = dfs(root->left);
            if (root->left->val == root->val + 1) {
                length = max(length, 1 + left);
            }
        }

        if (root->right) {
            auto right = dfs(root->right);
            if (root->right->val == root->val + 1) {
                length = max(length, 1 + right);
            }
        }

        answer = max(answer, length);
        return length;
    }
};