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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        mapping = unordered_map<string, TreeNode*>();
        counter = unordered_map<string, int>();
        
        postorderTraverse(root);
        
        vector<TreeNode*> answer;
        for (auto &[key, count]: counter) {
            if (count > 1) {
                answer.push_back(mapping[key]);
            }
        }
        
        return answer;
    }
    
private:
    unordered_map<string, TreeNode*> mapping;
    unordered_map<string, int> counter;
    
    string postorderTraverse(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }
        
        string left = postorderTraverse(root->left);
        string right = postorderTraverse(root->right);
        string val = to_string(root->val);
        
        string key = "(" + left + ")" + val + "(" + right + ")";
        
        counter[key]++;
        if (mapping.count(key) == 0) {
            mapping[key] = root;
        }
        
        return key;
    }
};
