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
#include <cstring> // for memset
using namespace std; // since cin and cout are both in namespace std, this saves some text

const int MAX_NUM_WORDS = 300;

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {        
        mapping = unordered_map<string, int>();
        for (int i = 0; i < strs.size(); ++i) {
            parents[i] = i;
            mapping[strs[i]] = i;
        }
                
        for (int i = 0; i < strs.size(); ++i) {
            string word = strs[i];
            unionSet(i, mapping[word]);

            for (int a = 0; a < word.size(); a++) {
                for (int b = a + 1; b < word.size(); b++) {
                    swapChar(word, a, b);
                    if (mapping.count(word) > 0) {
                        unionSet(i, mapping[word]);
                    }
                    swapChar(word, a, b);
                }   
            }
        }
        
        unordered_set<int> groups;
        for (int i = 0; i < strs.size(); ++i) {
            groups.insert(find(parents[i]));
        }
        
        return groups.size();
    }
    
private:
    int parents[MAX_NUM_WORDS + 1];
    unordered_map<string, int> mapping;
    
    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }
    
    void unionSet(int x, int y) {
        // path compression
        x = find(x);
        y = find(y);
        
        if (x == y) {
            return;
        }
        
        // TODO: add union by size if needed
        parents[y] = x;
    }
    
    void swapChar(string& word, int a, int b) {
        char temp = word[a];
        word[a] = word[b];
        word[b] = temp;
    }
};

class WASolution {
public:
    int numSimilarGroups(vector<string>& strs) {
        for (int i = 0; i < strs.size(); ++i) {
            parents[i] = i;
        }
        mapping = unordered_map<string, int>();
                
        for (int i = 0; i < strs.size(); ++i) {
            string word = strs[i];
            
            auto allSimilarWords = buildSimilarsWords(word);
            for (string reordered: allSimilarWords) {
                if (mapping.count(reordered) > 0) {
                    unionSet(i, mapping[reordered]);
                } else {
                    mapping[reordered] = i;
                }
            }
        }
        
        unordered_set<int> groups;
        for (int i = 0; i < strs.size(); ++i) {
            groups.insert(parents[i]);
        }
        
        return groups.size();
    }
    
private:
    int parents[MAX_NUM_WORDS + 1];
    unordered_map<string, int> mapping;
    
    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }
    
    void unionSet(int x, int y) {
        // path compression
        x = find(x);
        y = find(y);
        
        if (x == y) {
            return;
        }
        
        // TODO: add union by size if needed
        parents[y] = x;
    }
    
    unordered_set<string> buildSimilarsWords(string word) {
        unordered_set<string> allSimilarWords;
        
        allSimilarWords.insert(word);
        
        for (int i = 0; i < word.size(); i++) {
            for (int j = i + 1; j < word.size(); j++) {
                string reordered = string(word.begin(), word.end());
                char temp = reordered[i];
                reordered[i] = reordered[j];
                reordered[j] = temp;
                allSimilarWords.insert(reordered);
            }   
        }
        
        return allSimilarWords;
    }
};

class SlowSolution {
public:
    int numSimilarGroups(vector<string>& strs) {
        for (int i = 0; i < strs.size(); ++i) {
            parents[i] = i;
        }
        
        for (int i = 0; i < strs.size(); ++i) {
            for (int j = i + 1; j < strs.size(); ++j) {
                if (find(i) == find(j)) {
                    continue;
                }
                
                if (isSimilar(strs[i], strs[j])) {
                    unionSet(i, j);
                }
            }
        }
        
        unordered_set<int> groups;
        for (int i = 0; i < strs.size(); ++i) {
            groups.insert(parents[i]);
        }
        
        return groups.size();
    }
    
private:
    int parents[MAX_NUM_WORDS + 1];
    
    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }
    
    void unionSet(int x, int y) {
        // path compression
        x = find(x);
        y = find(y);
        
        if (x == y) {
            return;
        }
        
        // TODO: add union by size if needed
        parents[y] = x;
    }
    
    bool isSimilar(string word1, string word2) {
        // TODO
        return false;
    }
};

int main() {
    Solution soln;
    // vector<string> strs = {"koqnn", "knnqo", "oqnk", "nqkon"};
    // vector<string> strs = {"koqnn","knnqo","noqnk","nqkon"};
    vector<string> strs = {"ajdidocuyh","djdyaohuic","ddjyhuicoa","djdhaoyuic","ddjoiuycha","ddhoiuycja","ajdydocuih","ddjiouycha","ajdydohuic","ddjyouicha"};
    cout << soln.numSimilarGroups(strs) << endl;
    return 0;
}