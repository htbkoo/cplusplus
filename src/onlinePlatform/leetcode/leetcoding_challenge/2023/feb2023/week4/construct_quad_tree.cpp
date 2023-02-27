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
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        // TODO: validate input
        int n = grid.size();
        return construct(grid, 0, n - 1, 0, n - 1);
    }
    
private:
    Node* construct(vector<vector<int>>& grid, int ylo, int yhi, int xlo, int xhi) {
        int val = getVal(grid, ylo, yhi, xlo, xhi);
        int MULTIVAL = -1;
        bool VAL_FOR_NON_LEAF = true;
        if (val == MULTIVAL) {
            int ymid = ylo + (yhi - ylo) / 2;
            int xmid = xlo + (xhi - xlo) / 2;
            return new Node(
                VAL_FOR_NON_LEAF,
                false,
                construct(grid, ylo, ymid, xlo, xmid),
                construct(grid, ylo, ymid, xmid + 1, xhi),
                construct(grid, ymid + 1, yhi, xlo, xmid),
                construct(grid, ymid + 1, yhi, xmid + 1, xhi)
            );
        } else {
            return new Node(val == 1, true);
        }
    }
    
    int getVal(vector<vector<int>>& grid, int ylo, int yhi, int xlo, int xhi) {
        int MULTIVAL = -1;
        int val = grid[ylo][xlo];
        for (int y = ylo; y <= yhi; y++) {
            for (int x = xlo; x <= xhi; x++) {
                if (grid[y][x] != val) {
                    return MULTIVAL;
                }
            }
        }
        return val;
    }
};