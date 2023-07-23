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
    vector<TreeNode*> allPossibleFBT(int n) {
        if (memo.count(n) > 0) {
            return memo[n];
        }
        
        if (n % 2 == 0) {
            return {};   
        }
        
        if (n == 1) {
            return {new TreeNode(0)};
        } else {
            memo[n] = {};
            for (int leftSize = 1; leftSize <= n - 1; leftSize += 2) {
                for (auto left: allPossibleFBT(leftSize)) {
                    for (auto right: allPossibleFBT(n - 1 - leftSize)) {
                        memo[n].push_back(new TreeNode(0, left, right));
                    }
                }
            }
            return memo[n];
        }
    }
    
private:
    unordered_map<int, vector<TreeNode*>> memo;
};