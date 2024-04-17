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
    string smallestFromLeaf(TreeNode* root) {        
        if (root == nullptr) {
            // TODO: confirm this
            return "";
        }
        
        dfs(root, "");
        
        return answer;
    }
    
private:
    string answer;
    
    void dfs(TreeNode* root, string curr) {
        if (root == nullptr) {
            return;
        }
        
        curr = toChar(root->val) + curr;
        
        bool isLeaf = root->left == nullptr && root->right == nullptr;
        if (isLeaf) {
            if (answer == "" || curr < answer) {
                answer = curr;
            }
            return;
        } else {
            dfs(root->left, curr);
            dfs(root->right, curr);
        }
        
        curr = curr.substr(1, curr.size() - 1);
        
        return;
    }
    
    char toChar(int val) {
        return char(97 + val);
    }
};
