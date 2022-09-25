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
#include <string>
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return {};
        }
        
        bool isLeaf = root->left == nullptr && root->right == nullptr;
        if (isLeaf) {
            if (root->val == targetSum) {                
                return {{root->val}};
            } else {
                return {};
            }
        }
        
        auto remainTargetSum = targetSum - root->val;
        auto left = pathSum(root->left, remainTargetSum);
        auto right = pathSum(root->right, remainTargetSum);
        
        vector<vector<int>> answer;
        
        for (auto tail: left) {
            vector<int> path = {root->val};
            path.insert(path.end(), tail.begin(), tail.end());
            answer.push_back(path);
        }
        
        for (auto tail: right) {
            vector<int> path = {root->val};
            path.insert(path.end(), tail.begin(), tail.end());
            answer.push_back(path);
        }
        
        return answer;
    }
};