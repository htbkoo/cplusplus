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
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> maxLengths = vector<int>(text2.size() + 1);
        int answer;
        
        for (int i = 0; i < text1.size(); i++) {
            vector<int> prev = maxLengths;
            maxLengths = vector<int>(text2.size() + 1);
            for (int j = 0; j < text2.size(); j++) {
                if (text1[i] == text2[j]) {
                    maxLengths[j + 1] = prev[j] + 1;
                    answer = max(answer, maxLengths[j + 1]);
                } else {
                    maxLengths[j + 1] = max(prev[j + 1], maxLengths[j]);
                }
            }
        }
        
        // return *max(maxLengths.begin(), maxLengths.end());
        return answer;
    }
};

class WASolution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> maxLengths = vector<int>(text2.size() + 1);
        
        int answer = 0;
        
        for (int i = 0; i < text1.size(); i++) {
            for (int j = text2.size() - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    maxLengths[j + 1] = max({maxLengths[j + 1], maxLengths[j], maxLengths[j] + 1});
                    answer = max(answer, maxLengths[j + 1]);
                } else {
                    maxLengths[j + 1] = max(maxLengths[j + 1], maxLengths[j]);
                }
            }
        }
        
        // return *max(maxLengths.begin(), maxLengths.end());
        return answer;
    }
};

int main() {
    Solution soln;
    // cout << soln.longestCommonSubsequence("abc", "def") << endl;
    cout << soln.longestCommonSubsequence("hofubmnylkra",  "pqhgxgdofcvmr") << endl;
}