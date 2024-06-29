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
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        if (root == nullptr) {
            return vector<TreeNode*>{nullptr, nullptr};
        }
        
        if (target < root->val) {            
            auto result = splitBST(root->left, target);
            
            auto small = result[0];
            auto large = result[1];
            
            root->left = large;
            
            return vector{small, root};
        } else {
            auto result = splitBST(root->right, target);
            
            auto small = result[0];
            auto large = result[1];
            
            root->right = small;
            
            return vector{root, large};
        }
    }
};