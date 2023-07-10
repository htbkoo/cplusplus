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
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        deque<TreeNode*> dq;
        dq.push_back(root);
        
        int depth = 1;
        while (dq.size() > 0) {
            int count = dq.size();
            
            for (int i = 0; i < count; ++i) {
                auto node = dq.front();
                dq.pop_front();
                
                if (node->left == nullptr && node->right==nullptr) {
                    return depth;
                } 
                if (node->left != nullptr) {
                    dq.push_back(node->left);
                }
                if (node->right != nullptr) {
                    dq.push_back(node->right);
                }
            }
            
            depth++;
        }
        
        return depth;
    }
};