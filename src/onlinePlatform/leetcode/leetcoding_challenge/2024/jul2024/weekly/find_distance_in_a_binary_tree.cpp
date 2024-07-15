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

int NONE = numeric_limits<int>::min();

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
    int findDistance(TreeNode* root, int p, int q) {
        if (p == q) {
            return 0;
        }
        auto [answer, _, __] = find(root, p, q);
        return answer;
    }

private:
    tuple<int, int, int> find(TreeNode* root, int p, int q) {
        if (root == nullptr) {
            return tuple{NONE, NONE, NONE};
        }

        auto [leftAnswer, leftPDist, leftQDist] = find(root->left, p, q);
        if (leftAnswer >= 0) {
            return tuple{leftAnswer, NONE, NONE};
        }

        auto [rightAnswer, rightPDist, rightQDist] = find(root->right, p, q);
        if (rightAnswer >= 0) {
            return tuple{rightAnswer, NONE, NONE};
        }

        if (leftPDist >= 0 && rightQDist >= 0) {
            return tuple{leftPDist + rightQDist, NONE, NONE};
        }
        if (leftQDist >= 0 && rightPDist >= 0) {
            return tuple{leftQDist + rightPDist, NONE, NONE};
        }

        int pDist = max(NONE, max(leftPDist, rightPDist));
        if (root->val == p) {
            pDist = 0;
        }
        int qDist = max(NONE, max(leftQDist, rightQDist));
        if (root->val == q) {
            qDist = 0;
        }
        if (pDist >= 0 && qDist >= 0) {
            return tuple{pDist + qDist, NONE, NONE};
        }

        return {NONE, pDist + 1, qDist + 1};
    }
};
