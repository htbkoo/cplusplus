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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if (root == nullptr) {
            return {};
        }
        
        unordered_set<int> toDelete(begin(to_delete), end(to_delete));
        
        answer = vector<TreeNode*>();
        if (toDelete.count(root->val) == 0) {
            answer.push_back(root);
        }
        
        del(root, toDelete);
        
        return answer;
    }
    
private:
    vector<TreeNode*> answer;
    
    bool del(TreeNode* node, unordered_set<int>& toDelete) {
        if (node == nullptr) {
            return false;
        }
        
        if (del(node->left, toDelete)) {
            node->left = nullptr;
        }
        if (del(node->right, toDelete)) {
            node->right = nullptr;
        }        
        
        if (toDelete.count(node->val) > 0) {
            for (auto child: {node->left, node->right}) {
                if (child != nullptr) {
                    answer.push_back(child);
                }
            }
            return true;
        } else {
            return false;
        }
    }
};