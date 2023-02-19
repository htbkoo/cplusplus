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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        
        queue<TreeNode*> curr({root});
        
        // TODO: migrate this to enum for clarity
        int direction = 1;
        
        while (curr.size() > 0) {
            vector<int> layer;
            
            int count = curr.size();
                        
            for (int i = 0; i < count; i++) {                
                TreeNode* node = curr.front();
                curr.pop();
                    
                if (node == nullptr) {
                    continue;
                }
                
                layer.push_back(node->val);
                
                curr.push(node->left);
                curr.push(node->right);
            }
            
            if (direction == -1) {
                reverse(layer.begin(), layer.end());
            }
            
            if (layer.size() > 0) {
                answer.push_back(layer);   
            }
            
            direction *= -1;
        }
        
        return answer;
    }
};