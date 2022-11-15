#include <algorithm>
#include <cmath>
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
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }

        int layer = 1;
        TreeNode* curr = root;
        while (curr->left != nullptr) {
          layer++;
          curr = curr->left;
        }

        int lo = (int)pow(2, layer - 1);
        int hi = (int)pow(2, layer) - 1;
        
        while (lo < hi) {
            update(lo, hi, root);
        }
        
        return lo;
    }
    
private:
    string toBinary(int n) {
        if (n == 0) {
            return "0";
        } else {
            // vector<string> stack;
            vector<char> stack;
            while (n > 0) {
                // stack.push_back(to_string(n % 2));
                stack.push_back(n % 2 + '0');
                n /= 2;
            }
            reverse(stack.begin(), stack.end());
            return string(stack.begin(), stack.end());
        }
    }
    
    void update(int& lo, int& hi, TreeNode* curr) {
        int mid = (lo + hi + 1) / 2;
        string midBin = toBinary(mid);

        for (int i = 1; i < midBin.size(); i++) {                
            if (midBin[i] == '0') {
                curr = curr -> left;
            } else {
                curr = curr -> right;
            }
            if (curr == nullptr) {
                hi = mid - 1;
                return;
            }
        }
        
        lo = mid;
    }
};