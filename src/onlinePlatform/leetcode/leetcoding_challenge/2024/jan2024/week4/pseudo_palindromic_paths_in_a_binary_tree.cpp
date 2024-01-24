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
const int UNINITIALIZED = -1;

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
    int pseudoPalindromicPaths (TreeNode* root) {
        int MAX_NUM = 9;

        vector<int> counter(MAX_NUM + 1, 0);

        return getCount(root, counter);
    }

private:
    int getCount(TreeNode* root, vector<int>& counter) {
        if (root == nullptr) {
            return 0;
        }

        counter[root->val]++;

        int answer = 0;
        bool isLeaf = root->left == nullptr && root->right == nullptr;
        if (isLeaf) {
            if (isPseudoPalindromic(counter)) {
                answer++;
            }
        } else {
            for (auto child: {root->left, root->right}) {
                answer += getCount(child, counter);
            }
        }

        counter[root->val]--;
        return answer;
    }

    bool isPseudoPalindromic(vector<int>& counter) {
        bool hasOdd = false;
        for (auto count: counter) {
            if (count % 2 != 0) {
                if (hasOdd) {
                    return false;
                }
                hasOdd = true;
            }
        }
        return true;
    }
};

int main() {
    Solution soln;
    auto* root = new TreeNode(
        2,
        new TreeNode(
            3,
            new TreeNode(3),
            new TreeNode(1)
        ),
        new TreeNode(
        1,
        nullptr,
        new TreeNode(1)
        )
    );

    cout << soln.pseudoPalindromicPaths(root) << endl;

    return 0;
}