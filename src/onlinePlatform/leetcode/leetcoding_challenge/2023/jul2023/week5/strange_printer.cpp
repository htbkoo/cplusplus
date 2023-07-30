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

const int UNINITIALIZED = 9999999;

class Solution {
public:
    int strangePrinter(string s) {
        chPositions = vector<vector<int>>();
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            chPositions.push_back(vector<int>());
        }
        
        for (int i = 0; i < s.size(); ++i) {
            auto ch = s[i];
            chPositions[ch - 'a'].push_back(i);
        }
        
        memo = vector<vector<int>>();
        for (int i = 0; i <= s.size(); ++i) {
            memo.push_back(vector<int>(s.size() + 1, UNINITIALIZED));
        }
        
        return findMin(s, 0, s.size() - 1);
    }
    
private:
    vector<vector<int>> chPositions;
    
    vector<vector<int>> memo;
    
    int findMin(string& s, int lo, int hi) {
        cout << lo << " " << hi << endl;

        if (lo > hi) {
            return 0;
        }
        
        if (lo == hi) {
            return 1;
        }
        
        if (memo[lo][hi] != UNINITIALIZED) {
            return memo[lo][hi];
        }
        
        auto chIdx = s[lo] - 'a';
        auto it = lower_bound(chPositions[chIdx].begin(), chPositions[chIdx].end(), lo);

        // cout << "size: " << chPositions[chIdx].size() << " dist: " << distance(chPositions[chIdx].begin(), it) << " isEnd: " << (it == chPositions[chIdx].end()) << endl; 
        
        while (it != chPositions[chIdx].end()) {        
            auto nextHi = *it;
            int turns = 1 + findMin(s, nextHi + 1, hi);

            cout << nextHi << "_" << turns << endl;
 
            if (it != chPositions[chIdx].begin()) {
                auto prevPos = *prev(it);
                if (prevPos > lo) {
                    turns += findMin(s, prevPos + 1, nextHi - 1);
                }
            }
            
            cout << nextHi << "__" << turns << endl;

            memo[lo][hi] = min(
                memo[lo][hi],
                turns
            );
            
            it++;
        }
        
        cout << lo << " " << hi << ": " << memo[lo][hi] << endl;


        return memo[lo][hi];
    }
};

int main() {
    Solution soln;

    // string s = "aaabbb";
    string s = "aba";

    cout << soln.strangePrinter(s) << endl;

    return 0;
}