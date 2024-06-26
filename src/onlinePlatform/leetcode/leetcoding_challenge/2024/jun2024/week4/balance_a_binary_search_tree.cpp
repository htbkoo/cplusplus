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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        fillVector(root, v);

        return asBst(v, 0, v.size() - 1);
    }

private:
    void fillVector(TreeNode* root, vector<int>& v) {
        if (root == nullptr) {
            return;
        }

        fillVector(root->left, v);
        v.push_back(root->val);
        fillVector(root->right, v);
    }

    TreeNode* asBst(vector<int>& v, int lo, int hi) {
        if (lo > hi) {
            return nullptr;
        }

        int mid = lo + (hi - lo) / 2;
        int val = v[mid];

        auto left = asBst(v, lo, mid - 1);
        auto right = asBst(v, mid + 1, hi);

        return new TreeNode(
            val,
            left,
            right
        );
    }
};
