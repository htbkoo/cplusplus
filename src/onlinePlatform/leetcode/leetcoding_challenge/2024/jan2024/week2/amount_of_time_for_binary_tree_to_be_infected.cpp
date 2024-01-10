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
    int amountOfTime(TreeNode* root, int start) {
        return dfs(root, start)[2];
    }

private:
    // {dist, height, answer}
    vector<int> dfs(TreeNode* root, int start) {
        if (root == nullptr) {
            return {-1, -1, -1};
        }

        auto left = dfs(root->left, start);
        auto right = dfs(root->right, start);

        int answer = max(left[2], right[2]);
        int height = 1 + max(left[1], right[1]);
        int dist = -1;
        if (left[0] != -1) {
            dist = left[0] + 1;
            answer = max(answer, dist + 1 + right[1]);
        }
        if (right[0] != -1) {
            dist = right[0] + 1;
            answer = max(answer, dist + 1 + left[1]);
        }
        if (root->val == start) {
            dist = 0;
            answer = height;
        }

        return {dist, height, answer};
    }
};