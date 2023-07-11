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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (k == 0) {
            return vector<int>{target->val};
        }
        
        answer = vector<int>();
        
        findNode(root, target, k);
        
        return answer;
    }
    
private:
    vector<int> answer;
    
    int findNode(TreeNode* node, TreeNode* target, int k) {
        if (node == nullptr) {
            return -1;
        }
                
        if (node == target) {
            addChild(node, k);
            return k - 1;
        } else {
            int leftK = findNode(node->left, target, k);
            if (leftK >= 0) {
                if (leftK > 0) { 
                    addChild(node->right, leftK - 1);
                } else {
                    answer.push_back(node->val);
                }
                return leftK - 1;
            } else {
                int rightK = findNode(node->right, target, k);
                if (rightK >= 0) {        
                    if (rightK > 0) { 
                        addChild(node->left, rightK - 1);
                    } else {
                        answer.push_back(node->val);
                    }        
                    return rightK - 1;
                }
            }
            
            return -1;
        }
    }
    
    void addChild(TreeNode* node, int k) {
        if (node == nullptr || k < 0) {
            return;
        }

        if (k == 0) {
            answer.push_back(node->val);
            return;
        } else {
            addChild(node->left, k - 1);
            addChild(node->right, k - 1);
        }
    }
};