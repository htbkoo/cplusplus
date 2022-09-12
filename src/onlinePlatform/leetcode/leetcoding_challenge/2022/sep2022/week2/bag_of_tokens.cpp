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
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int maxScore = 0;
        int score = 0;
        
        tokens = vector(tokens);        
        sort(tokens.begin(), tokens.end());
        
        int left = 0;
        int right = tokens.size() - 1;
        
        while (left <= right) {
            if (power >= tokens[left]) {
                power -= tokens[left];
                score++;
                maxScore = max(maxScore, score);
                left++;
            } else {
                if (score >= 1) {
                    score--;
                    power += tokens[right];
                    right--;
                } else {
                    break;
                }
            }            
        }
                
        return maxScore;
    }
};