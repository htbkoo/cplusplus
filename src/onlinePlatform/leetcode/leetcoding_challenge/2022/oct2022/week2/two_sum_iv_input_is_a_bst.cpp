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
    bool findTarget(TreeNode* root, int k) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            // tree has 0 or 1 node only
            return false;
        }
        
        vector<int> v = asVector(root);
        int left = 0;
        int right = v.size() - 1;
        
        while (left < right) {
            long sum = v[left] + v[right];
            if (sum < k) {
                left++;
            } else if (sum > k) {
                right--;
            } else {
                return true;
            }
        }
        
        return false;
    }
    
    vector<int> asVector(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        
        vector<int> left = asVector(root->left);
        left.push_back(root->val);
        vector<int> right = asVector(root->right);
        left.insert(left.end(), right.begin(), right.end());
        
        return left;
    }
};