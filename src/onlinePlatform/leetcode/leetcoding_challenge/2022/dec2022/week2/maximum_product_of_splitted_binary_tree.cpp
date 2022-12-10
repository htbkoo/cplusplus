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
    int maxProduct(TreeNode* root) {
        totalSum = findMax(root);
        answer = numeric_limits<long>::min();
        findMax(root);
        
        int MOD = pow(10, 9) + 7;
        return answer % MOD;
    }
    
private:
    long totalSum = 0;
    long answer = 0;
    long findMax(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        } else {
            long leftSum = findMax(node->left);
            answer = max(answer, getProduct(leftSum));
            long rightSum = findMax(node->right);
            answer = max(answer, getProduct(rightSum));
            
            return ((long) node->val) + leftSum + rightSum;
        }
    }
    
    long getProduct(long first) {
        return first * (totalSum - first);
    }
};

class FirstSolution {
public:
    int maxProduct(TreeNode* root) {
        totalSum = getTotalSum(root);
        findMax(root);
        
        int MOD = pow(10, 9) + 7;
        return answer % MOD;
    }
    
private:
    long totalSum = 0;
    long answer = 0;
    long getTotalSum(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        } else {
            return ((long) node->val) + getTotalSum(node->left) + getTotalSum(node->right);
        }
    }
    
    long findMax(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        } else {
            long leftSum = findMax(node->left);
            answer = max(answer, getProduct(leftSum));
            long rightSum = findMax(node->right);
            answer = max(answer, getProduct(rightSum));
            
            return ((long) node->val) + leftSum + rightSum;
        }
    }
    
    long getProduct(long first) {
        return first * (totalSum - first);
    }
};