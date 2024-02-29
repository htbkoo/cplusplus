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
    bool isEvenOddTree(TreeNode* root) {
        vector<TreeNode*> rows{root};
        int level = 0;
        while (rows.size() > 0) {
            vector<TreeNode*> prev = rows;
            rows = vector<TreeNode*>();

            int prevVal = level % 2 == 0 ? numeric_limits<int>::min() : numeric_limits<int>::max();

            for (auto node: prev) {
                if (node == nullptr) {
                    continue;
                }

                if (level % 2 == 0) {
                    if ((node->val % 2 == 0) || (node->val <= prevVal)) {
                        return false;
                    }
                } else {
                    if ((node->val % 2 != 0) || (node->val >= prevVal)) {
                        return false;
                    }
                }

                prevVal = node->val;
                for (auto child: {node->left, node->right}) {
                    rows.push_back(child);
                }
            }

            level++;
        }

        return true;
    }
};