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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mapping;
        unordered_set<int> rootCandidates;
        unordered_set<int> children;

        for (auto &description: descriptions) {
            auto parent = description[0];
            auto child = description[1];
            auto isLeft = description[2];

            children.insert(child);
            if (mapping.count(child) == 0) {
                mapping[child] = new TreeNode(child);
            }

            rootCandidates.insert(parent);
            if (mapping.count(parent) == 0) {
                mapping[parent] = new TreeNode(parent);
            }

            if (isLeft == 1) {
                mapping[parent]->left = mapping[child];
            } else {
                mapping[parent]->right = mapping[child];
            }
        }

        for (auto child: children) {
            rootCandidates.erase(child);
        }

        return mapping[*begin(rootCandidates)];
    }
};

class WASolution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mapping;
        TreeNode* root;

        for (auto &description: descriptions) {
            auto parent = description[0];
            auto child = description[1];
            auto isLeft = description[2];

            if (mapping.count(child) == 0) {
                mapping[child] = new TreeNode(child);
            }

            if (mapping.count(parent) == 0) {
                mapping[parent] = new TreeNode(parent);
                root = mapping[parent];
            }

            if (isLeft == 1) {
                mapping[parent]->left = mapping[child];
            } else {
                mapping[parent]->right = mapping[child];
            }
        }

        return root;
    }
};
