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
    int minDistance(string word1, string word2) {
        vector<int> dists(word2.size() + 1, 0);
        for (int j = 0; j < word2.size(); j++) {
            dists[j + 1] = j + 1;
        }
        
        for (int i = 0; i < word1.size(); i++) {
            vector<int> nextDists(word2.size() + 1, 0);
            nextDists[0] = i + 1;
            
            for (int j = 0; j < word2.size(); j++) {
                nextDists[j + 1] = 1 + min({dists[j + 1], dists[j], nextDists[j]});
                if (word1[i] == word2[j]) {
                    nextDists[j + 1] = min(nextDists[j + 1], dists[j]);
                }
            }
            
            dists = nextDists;
        }
        
        return dists[dists.size() - 1];
    }
};
