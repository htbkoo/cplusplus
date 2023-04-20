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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            // TODO: confirm this
            return 0;
        }
        
        int answer = 0;
        queue<pair<TreeNode*, int>> q({pair{root, 0}});
        
        while (q.size() > 0) {
            int width = 1 + (q.back().second - q.front().second);
            answer = max(answer, width);
            
            int count = q.size();
            for (int i = 0; i < count; ++i) {
                auto [node, id] = q.front();
                q.pop();
                
                if (node->left != nullptr) {
                    q.push(pair{node->left, id * 2});
                }
                if (node->right != nullptr) {
                    q.push(pair{node->right, id * 2 + 1});
                }
            }
        }
        
        return answer;
    }
};