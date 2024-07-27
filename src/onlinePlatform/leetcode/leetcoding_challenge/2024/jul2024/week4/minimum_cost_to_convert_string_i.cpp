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
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        auto UNREACHABLE = numeric_limits<long long>::max();
        
        int NUM_LOWERCASE_CHARS = 26;
        vector<vector<long long>> dists(NUM_LOWERCASE_CHARS, vector<long long>(NUM_LOWERCASE_CHARS, UNREACHABLE));
        for (int ch = 'a'; ch <= 'z'; ++ch) {
            int idx = ch - 'a';
            dists[idx][idx] = 0;
        }
        
        for (int i = 0; i < cost.size(); ++i) {
            int fromCh = original[i];
            int fromIdx = fromCh - 'a';
            int toCh = changed[i];
            int toIdx = toCh - 'a';
            
            dists[fromIdx][toIdx] = min(dists[fromIdx][toIdx], (long long) cost[i]);
        }
        
        for (int k = 0; k < NUM_LOWERCASE_CHARS; ++k) {
            for (int i = 0; i < NUM_LOWERCASE_CHARS; ++i) {
                for (int j = 0; j < NUM_LOWERCASE_CHARS; ++j) {
                    if (UNREACHABLE == dists[i][k] || UNREACHABLE == dists[k][j]) {
                        continue;
                    }
                    
                    dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
                }
            }
        }
        
        long long answer = 0;
        
        for (int i = 0; i < source.size(); ++i) {
            int fromCh = source[i];
            int fromIdx = fromCh - 'a';
            int toCh = target[i];
            int toIdx = toCh - 'a';
            
            if (UNREACHABLE == dists[fromIdx][toIdx]) {
                return -1;
            }
                
            answer += dists[fromIdx][toIdx];
        }
        
        return answer;
    }
};
