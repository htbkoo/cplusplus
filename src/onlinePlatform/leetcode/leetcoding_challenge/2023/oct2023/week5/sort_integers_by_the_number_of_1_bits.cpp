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
    int averageOfSubtree(TreeNode* root) {
        answer = 0;
        getCountAndSum(root);
        return answer;
    }
    
private:
    int answer;
    
    pair<int, int> getCountAndSum(TreeNode* root) {
        if (root == nullptr) {
            return pair{0, 0};
        }
        
        auto [leftCount, leftSum] = getCountAndSum(root->left);
        auto [rightCount, rightSum] = getCountAndSum(root->right);
        
        int sum = leftSum + rightSum + root->val;
        int count = 1 + leftCount + rightCount;
        int avg = sum / count;
        if (avg == root->val) {
            answer++;
        }
        return pair{count, sum};
    }
};