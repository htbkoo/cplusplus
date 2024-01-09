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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        auto leaves1 = getLeaves(root1);
        auto leaves2 = getLeaves(root2);

        if (leaves1.size() != leaves2.size()) {
            return false;
        }

        for (int i = 0; i < leaves1.size(); ++i) {
            if (leaves1[i] != leaves2[i]) {
                return false;
            }
        }

        return true;
    }

private:
    vector<int> getLeaves(TreeNode* root) {
        vector<int> leaves;

        vector<TreeNode*> nodes{root};

        while (nodes.size() > 0) {
            auto node = nodes.back();
            nodes.pop_back();

            if (node == nullptr) {
                continue;
            }

            bool isLeaf = node->left == nullptr && node->right == nullptr;
            if (isLeaf) {
                leaves.push_back(node->val);
            } else {
                for (auto child: {node->right, node->left}) {
                    nodes.push_back(child);
                }
            }
        }

        return leaves;
    }
};