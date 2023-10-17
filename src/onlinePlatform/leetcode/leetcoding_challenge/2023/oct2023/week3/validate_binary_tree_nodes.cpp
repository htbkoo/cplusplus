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

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_set<int> appeared;
        for (auto children: {leftChild, rightChild}) {
            for (auto child: children) {
                if (child == -1) {
                    continue;
                }
                if (appeared.count(child) > 0) {
                    return false;
                }
                appeared.insert(child);
            }
        }
        
        if (appeared.size() != n - 1) {
            return false;
        }
        
        unordered_set<int> root;
        for (int i = 0; i < n; ++i) {
            root.insert(i);
        }        
        for (int i = 0; i < n; ++i) {
            root.erase(leftChild[i]);
            root.erase(rightChild[i]);
        }
        
        if (root.size() != 1) {
            return false;
        }
        
        int r = *root.begin();
        
        vector<bool> visited(n, false);
        
        vector<int> stack{r};
        while (stack.size() > 0) {
            int node = stack.back();

            if (node == -1) {
                continue;
            }

            if (visited[node]) {
                return false;
            }
            visited[node] = true;
            n -= 1;

            for (auto children: {leftChild, rightChild}) {
                stack.push_back(children[node]);
            }
        }
        
        return n == 0;
    }
};

class TLESolution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_set<int> appeared;
        for (auto children: {leftChild, rightChild}) {
            for (auto child: children) {
                if (child == -1) {
                    continue;
                }
                if (appeared.count(child) > 0) {
                    return false;
                }
                appeared.insert(child);
            }
        }
        
        if (appeared.size() != n - 1) {
            return false;
        }
        
        unordered_set<int> root;
        for (int i = 0; i < n; ++i) {
            root.insert(i);
        }        
        for (int i = 0; i < n; ++i) {
            root.erase(leftChild[i]);
            root.erase(rightChild[i]);
        }
        
        if (root.size() != 1) {
            return false;
        }
        
        int r = *root.begin();
        
        unordered_set<int> visited;
        
        vector<int> stack{r};
        while (stack.size() > 0) {
            int node = stack.back();

            if (node == -1) {
                continue;
            }

            if (visited.count(node) > 0) {
                return false;
            }
            visited.insert(node);

            for (auto children: {leftChild, rightChild}) {
                stack.push_back(children[node]);
            }
        }
        
        return visited.size() == n;
    }
};

class WASolution2 {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_set<int> appeared;
        for (auto children: {leftChild, rightChild}) {
            for (auto child: children) {
                if (child == -1) {
                    continue;
                }
                if (appeared.count(child) > 0) {
                    return false;
                }
                appeared.insert(child);
            }
        }
        
        if (appeared.size() != n - 1) {
            return false;
        }
        
        unordered_set<int> root;
        for (int i = 0; i < n; ++i) {
            root.insert(i);
        }        
        for (int i = 0; i < n; ++i) {
            root.erase(leftChild[i]);
            root.erase(rightChild[i]);
        }
        
        if (root.size() != 1) {
            return false;
        }
        
        int r = *root.begin();
        
        unordered_set<int> path;
        unordered_set<int> visited;
        
        vector<int> stack{r};
        while (stack.size() > 0) {
            int node = stack.back();
            stack.pop_back();

            if (node == -1) {
                continue;
            }

            visited.insert(node);

            if (path.count(node) > 0) {
                return false;
            }
            path.insert(node);

            for (auto children: {leftChild, rightChild}) {
                stack.push_back(children[node]);
            }

            path.erase(node);
        }
        
        return visited.size() == n;
    }
};

class MLESolution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_set<int> appeared;
        for (auto children: {leftChild, rightChild}) {
            for (auto child: children) {
                if (child == -1) {
                    continue;
                }
                if (appeared.count(child) > 0) {
                    return false;
                }
                appeared.insert(child);
            }
        }
        
        if (appeared.size() != n - 1) {
            return false;
        }
        
        unordered_set<int> root;
        for (int i = 0; i < n; ++i) {
            root.insert(i);
        }        
        for (int i = 0; i < n; ++i) {
            root.erase(leftChild[i]);
            root.erase(rightChild[i]);
        }
        
        if (root.size() != 1) {
            return false;
        }
        
        int r = *root.begin();
        
        unordered_set<int> path;
        unordered_set<int> visited;
        if (!dfs(r, leftChild, rightChild, path, visited)) {
            return false;
        }
        
        return visited.size() == n;
    }

private:
    bool dfs(int node, vector<int>& leftChild, vector<int>& rightChild, unordered_set<int>& path, unordered_set<int>& visited) {
        if (node == -1) {
            return true;
        }
        
        visited.insert(node);
        
        if (path.count(node) > 0) {
            return false;
        }
        path.insert(node);
        
        for (auto children: {leftChild, rightChild}) {
            if (children[node] != -1 && !dfs(children[node], leftChild, rightChild, path, visited)) {
                return false;
            }
        }
        
        path.erase(node);
        return true;
    }
};

class WASolution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_set<int> appeared;
        for (auto children: {leftChild, rightChild}) {
            for (auto child: children) {
                if (child == -1) {
                    continue;
                }
                if (appeared.count(child) > 0) {
                    return false;
                }
                appeared.insert(child);
            }
        }
        
        return appeared.size() == n - 1;
    }
};