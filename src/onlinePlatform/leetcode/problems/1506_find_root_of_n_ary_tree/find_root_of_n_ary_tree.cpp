#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* findRoot(vector<Node*> tree) {
        int total = 0;

        for (auto node: tree) {
            total += node->val;
            for (auto child: node->children) {
                total -= child->val;
            }
        }

        for (auto node: tree) {
            if (total == node->val) {
                return node;
            }
        }

        throw invalid_argument("unable to find the root");
    }
};