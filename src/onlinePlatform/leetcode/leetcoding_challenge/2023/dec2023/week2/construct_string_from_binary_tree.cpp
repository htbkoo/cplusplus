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
    string tree2str(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }

        string answer = to_string(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            return answer;
        }

        if (root->left == nullptr) {
            return answer + "(" + ")" + "(" + tree2str(root->right) + ")";
        }

        if (root->right == nullptr) {
            return answer + "(" + tree2str(root->left) + ")";
        }

        return answer + "(" + tree2str(root->left) + ")" + "(" + tree2str(root->right) + ")";
    }
};

class WASolution {
public:
    string tree2str(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }

        string answer = to_string(root->val);

        for (auto child: {root->left, root->right}) {
            if (child == nullptr) {
                continue;
            }
            answer += "(" + tree2str(child) + ")";
        }

        return answer;
    }
};