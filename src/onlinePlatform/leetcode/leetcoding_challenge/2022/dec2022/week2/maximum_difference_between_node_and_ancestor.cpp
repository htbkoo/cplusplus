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
    int maxAncestorDiff(TreeNode* root) {
        // TODO: clarify: what if root is empty?
        if (root == nullptr) {
            throw invalid_argument("root is empty");
            // return 0;
        }
        
        return findMaxDiff(root, root->val, root->val);
    }
    
private:    
    int findMaxDiff(TreeNode* node, int minVal, int maxVal) {
        if (node == nullptr) {
            return 0;
        }
        
        minVal = min(minVal, node->val);
        maxVal = max(maxVal, node->val);
        
        int diff = maxVal - minVal;
        return max({
            diff,
            findMaxDiff(node->left, minVal, maxVal),
            findMaxDiff(node->right, minVal, maxVal),
        });
    }
};
