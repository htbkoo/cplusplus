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
    int maxLevelSum(TreeNode* root) {
        if (root == nullptr) {
            throw invalid_argument("tree is empty");
        }
        
        int level = 1;
        
        int maxLevel = 1;
        long maxSum = numeric_limits<long>::min(); 
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (q.size() > 0) {
            int numNodes = q.size();
            long sum = 0;
            for (int i = 0; i < numNodes; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                sum += node->val;
                
                for (auto child: {node->left, node->right}) {
                    if (child != nullptr) {
                        q.push(child);
                    }
                }
            }
            
            if (sum > maxSum) {
                maxLevel = level;
                maxSum = sum;
            }
            
            level++;
        }
        
        return maxLevel;        
    }
};

class WASolution {
public:
    int maxLevelSum(TreeNode* root) {
        if (root == nullptr) {
            throw invalid_argument("tree is empty");
        }
        
        int level = 1;
        
        int maxLevel = 1;
        long maxSum = numeric_limits<long>::min(); 
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (q.size() > 0) {
            int numNodes = q.size();
            long sum = 0;
            for (int i = 0; i < numNodes; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                if (node == nullptr) {
                    continue;
                }
                
                sum += node->val;
                
                for (auto child: {node->left, node->right}) {
                    q.push(child);
                }
            }
            
            if (sum > maxSum) {
                maxLevel = level;
                maxSum = sum;
            }
            
            level++;
        }
        
        return maxLevel;        
    }
};