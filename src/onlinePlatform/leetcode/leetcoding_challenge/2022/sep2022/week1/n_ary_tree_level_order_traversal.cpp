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

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> answer;

        if (root) {
            queue<Node*> q;
            q.push(root);

            while (q.size() > 0) {
                auto size = q.size();
                vector<int> layer;
                for (auto i = 0; i < size; i++) {
                    auto node = q.front();
                    q.pop();

                    layer.push_back(node->val);

                    for (Node* child: node->children) {
                        q.push(child);
                    }
                }

                answer.push_back(layer);
            }
        }


        return answer;
    }
};
