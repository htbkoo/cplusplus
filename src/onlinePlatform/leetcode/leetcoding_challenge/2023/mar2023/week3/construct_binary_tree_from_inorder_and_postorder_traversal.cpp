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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            int val = inorder[i];
            inPositions[val] = i;
            postPositions[val] = i;
        }
        
        int numNodes = inorder.size();
        return build(inorder, postorder, 0, numNodes - 1, 0, numNodes - 1);
    }
    
private:
    unordered_map<int, int> inPositions;
    unordered_map<int, int> postPositions;
    
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inLo, int inHi, int postLo, int postHi) {
        if (postLo > postHi) {
            return nullptr;
        }
        
        int rootVal = postorder[postHi];
        int inPos = inPositions[rootVal];
        
        int rightSize = inHi - inPos;
        
        TreeNode* rightNode = build(inorder, postorder, inPos + 1, inHi, postHi - rightSize, postHi - 1);
        
        
        TreeNode* leftNode = build(inorder, postorder, inLo, inPos - 1, postLo, postHi - rightSize - 1);
        
        TreeNode* root = new TreeNode(rootVal, leftNode, rightNode);
        
        return root;
    }
    
};
