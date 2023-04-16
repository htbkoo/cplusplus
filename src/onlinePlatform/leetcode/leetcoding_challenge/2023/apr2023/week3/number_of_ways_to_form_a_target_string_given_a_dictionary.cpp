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
    int numWays(vector<string>& words, string target) {
        if (words.size() == 0) {
            // TODO: confirm this
            return 0;
         } 

        wordSize = words[0].size();

        memo = unordered_map<int, unordered_map<int, long long>>();
        
        positionToCharsToCountMap = map<int, unordered_map<char, int>>();
        for (auto word: words) {
            for (int k = 0; k < wordSize ; ++k) {
                char ch = word[k];
                positionToCharsToCountMap[k][ch]++;
            }
        }
        
        return count(target, 0, 0) % MOD;
    }
    
private:
    long long MOD = pow(10, 9) + 7;

    unordered_map<int, unordered_map<int, long long>> memo;
    map<int, unordered_map<char, int>> positionToCharsToCountMap;
    int wordSize;
    
    long long count(string& target, int i, int k) {
        if (i == target.size()) {
            return 1;
        }
        if (k >= wordSize) {
            return 0;
        }
        
        if (memo.count(i) > 0 && memo[i].count(k) > 0) {
            return memo[i][k];
        }

        char ch = target[i];
        memo[i][k] = (
            count(target, i, k + 1) 
            + (positionToCharsToCountMap[k][ch] * count(target, i + 1, k + 1)) % MOD
        ) % MOD;

        return memo[i][k];
    }
};

class TLESolution {
public:
    int numWays(vector<string>& words, string target) {
        memo = unordered_map<int, unordered_map<int, int>>();
        
        charsToPositionToCountMap = unordered_map<char, map<int, int>>();
        for (auto word: words) {
            for (int i = 0; i < word.size(); ++i) {
                char ch = word[i];
                charsToPositionToCountMap[ch][i]++;
            }
        }
        
        return count(target, 0, -1) % MOD;
    }
    
private:
    long long MOD = pow(10, 9) + 7;

    unordered_map<int, unordered_map<int, int>> memo;
    unordered_map<char, map<int, int>> charsToPositionToCountMap;
    
    long long count(string& target, int i, int k) {
        if (i == target.size()) {
            return 1;
        }
        
        if (memo.count(i) > 0 && memo[i].count(k) > 0) {
            return memo[i][k];
        }
        memo[i][k] = 0;
        
        char ch = target[i];
        
        for (auto it = charsToPositionToCountMap[ch].upper_bound(k); it != charsToPositionToCountMap[ch].end(); ++it) {
            int pos = it->first;
            int occurrences = it->second;
            
            memo[i][k] = (memo[i][k] + (long long) occurrences * count(target, i + 1, pos)) % MOD;
        }
        
        return memo[i][k];
    }
};