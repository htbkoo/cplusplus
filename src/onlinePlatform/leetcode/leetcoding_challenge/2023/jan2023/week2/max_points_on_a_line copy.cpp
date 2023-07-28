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

class UnionFind {
public:
    UnionFind() {
        parents = unordered_map<char, char>();
        for (char ch = 'a'; ch <= 'z'; ch++) {
            parents[ch] = ch;
        }
    }
    
    char find(char x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }
    
    void unionTwo(char x, char y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (x < y) {
            parents[y] = x;
        } else {
            parents[x] = y;
        }
    }
    
private:
    unordered_map<char, char> parents;
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {        
        UnionFind uf;
        // TODO: validate input, e.g. if s1.size() != s2.size()
        for (int i = 0; i < s1.size(); i++) {
            uf.unionTwo(s1[i], s2[i]);
        }
        
        string answer(baseStr);
        for (int i = 0; i < answer.size(); i++) {
            answer[i] = uf.find(answer[i]);
        }
        
        return answer;
    }
};