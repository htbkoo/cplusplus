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
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) {
            // TODO: confirm this
            return 0;
        }
        
        answer = 0;
        
        vector<int> stack;
        dfs(root, stack);
        
        return answer;
    }
    
private:
    int answer;
    
    void dfs(TreeNode* root, vector<int>& stack) {
        stack.push_back(root->val);

        bool isLeaf = root->left == nullptr && root->right == nullptr;
        if (isLeaf) {
            answer += asInt(stack);
        } else {
            for (auto child: {root->left, root->right}) {
                if (child != nullptr) {
                    dfs(child, stack);
                }
            }
        }
        
        stack.pop_back();
        return;
    }
    
    int asInt(vector<int>& stack) {
        int total = 0;        
        for (int digit: stack) {
            total *= 10;
            total += digit;
        }
        return total;
    }
};