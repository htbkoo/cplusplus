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
    int longestStrChain(vector<string>& words) {
        if (words.size() == 0) {
            return 0;
        }
        
        int answer = 1;
        unordered_map<string, int> best;
        
        int longestWordLength = 0;
        
        unordered_map<int, vector<string>> wordsGroupBySize;
        for (auto word: words) {
            wordsGroupBySize[word.size()].push_back(word);
            longestWordLength = max(longestWordLength, (int) word.size());
        }
        
        for (int i = 1; i <= longestWordLength; ++i) {
            for (auto word: wordsGroupBySize[i]) {
                best[word] = 1;
                for (auto shorter: wordsGroupBySize[i - 1]) {
                    if (isPredecessor(shorter, word)) {
                        best[word] = max(best[word], best[shorter] + 1);
                    }
                }
                answer = max(answer, best[word]);
            }
        }
        
        return answer;
    }
    
private:
    bool isPredecessor(string word1, string word2) {
        if (word1.size() + 1 != word2.size()) {
            return false;
        }
        
        int i = 0;
        int j = 0;
        
        bool inserted = false;
        while (i < word1.size() && j < word2.size()) {
            if (word1[i] == word2[j]) {
                i += 1;
            } else {
                if (inserted) {
                    return false;
                } else {
                    inserted = true;
                }
            }
            j += 1;
        }
        
        return true;
    }
};