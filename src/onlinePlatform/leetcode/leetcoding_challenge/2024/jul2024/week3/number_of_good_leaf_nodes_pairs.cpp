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
    int countPairs(TreeNode* root, int distance) {
        answer = 0;
        
        count(root, distance);
        
        return answer;
    }
    
private:
    int answer;
    
    map<int, int> count(TreeNode* node, int distance) {
        if (node == nullptr) {
            return {};
        }
        
        bool isLeaf = node->left == nullptr && node->right == nullptr;
        if (isLeaf) {
            return {{1, 1}};
        }
        
        map<int, int> combined;
        
        auto leftMap = count(node->left, distance);
        auto rightMap = count(node->right, distance);
        
        for (auto& [distLeft, countLeft]: leftMap) {
            if (distLeft > distance) {
                break;
            }
            
            for (auto& [distRight, countRight]: rightMap) {
                if (distLeft + distRight > distance) {
                    break;
                }
                answer += countLeft * countRight;
            }        
        }
        
        for (auto childMap: {leftMap, rightMap}) {
            for (auto& [dist, count]: childMap) {
                if (dist + 1 > distance) {
                    break;
                }
                combined[dist + 1] += count;
            }
        }
        
        return combined;
    }
};