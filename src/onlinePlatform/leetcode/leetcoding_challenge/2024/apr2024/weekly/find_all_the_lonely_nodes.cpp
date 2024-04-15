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
    vector<int> getLonelyNodes(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        
        if (root->left == nullptr && root->right == nullptr) {
            return {};
        }
        
        if (root->left == nullptr) {
            vector<int> answer{root->right->val};
            for (auto v: getLonelyNodes(root->right)) {
                answer.push_back(v);
            }
            return answer;
        }
        
        if (root->right == nullptr) {
            vector<int> answer{root->left->val};
            for (auto v: getLonelyNodes(root->left)) {
                answer.push_back(v);
            }
            return answer;
        }
        
        vector<int> answer;
        for (auto child: {root->left, root->right}) {
            for (auto v: getLonelyNodes(child)) {
                answer.push_back(v);
            }
        }
        return answer;
    }
};