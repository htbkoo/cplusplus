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
    int getMinimumDifference(TreeNode* root) {
        if (root == nullptr) {
            throw invalid_argument("tree is empty");
        }
        if (root->left == nullptr && root->right == nullptr) {
            throw invalid_argument("tree has only one node");
        }
        
        answer = numeric_limits<int>::max();
        findMinDiff(root, numeric_limits<int>::max() / 2);
        return answer;
    }
    
private:
    int answer;
    
    int findMinDiff(TreeNode* root, int prev) {
        answer = min(answer, abs(prev - root->val));
        
        if (root->left != nullptr) {
            int leftMax = findMinDiff(root->left, prev);
            answer = min(answer, abs(leftMax - root->val));
        }
        
        if (root->right != nullptr) {
            return findMinDiff(root->right, root->val);
        } else {
            return root->val;
        }
        
    }
};

class FirstSolution {
public:
    int getMinimumDifference(TreeNode* root) {
        if (root == nullptr) {
            throw invalid_argument("tree is empty");
        }
        if (root->left == nullptr && root->right == nullptr) {
            throw invalid_argument("tree has only one node");
        }

        vector<int> v;
        toVector(root, v);
        
        answer = v[1] - v[0];
        for (int i = 2; i < v.size(); i++) {
            answer = min(answer, v[i] - v[i - 1]);
        }
        
        return answer;
    }
    
private:
    int answer;
    
    void toVector(TreeNode* root, vector<int>& v) {
        if (root == nullptr) {
            return;
        }
        
        toVector(root->left, v);
        v.push_back(root->val);
        toVector(root->right, v);
    }
};

class WASolution {
public:
    int getMinimumDifference(TreeNode* root) {
        if (root == nullptr) {
            throw invalid_argument("tree is empty");
        }
        if (root->left == nullptr && root->right == nullptr) {
            throw invalid_argument("tree has only one node");
        }
        
        return findMinDiff(root, numeric_limits<int>::min() / 2, -numeric_limits<int>::max() / 2);
    }
    
private:
    int findMinDiff(TreeNode* root, int lo, int hi) {
        if (root == nullptr) {
            return numeric_limits<int>::max();
        }
        
        int answer = min(abs(root->val - lo), abs(root->val - hi));
        
        lo = min(lo, root->val);
        hi = max(hi, root->val);
        
        return min(
            answer,
            min(
                findMinDiff(root->left, lo, hi),
                findMinDiff(root->right, lo, hi)
            )
        );
    }
};

int main() {
    Solution soln;

    TreeNode* root = new TreeNode(
        334, 
        new TreeNode(277,nullptr,new TreeNode(285)),
        new TreeNode(507,nullptr,new TreeNode(678))
    );

    cout << soln.getMinimumDifference(root) << endl;

    return 0;
}