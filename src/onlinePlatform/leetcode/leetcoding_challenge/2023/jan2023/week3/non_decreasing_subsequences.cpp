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
    vector<vector<int>> findSubsequences(vector<int>& nums) {        
        vector<vector<int>> answer;
        set<vector<int>> subsequences = build(nums, 0);
        for (vector<int> subsequence: subsequences) {
            if (subsequence.size() >= 2) {
                answer.push_back(subsequence);
            }
        }
        return answer;
    }
    
private:
    set<vector<int>> build(vector<int>& nums, int i) {
        set<vector<int>> s;
        if (nums.size() == 0) {
            return s;
        }
        
        int head = nums[i];
        s.insert({head});
        if (i >= nums.size() - 1) {
            return s;
        }
        
        for (; i < nums.size() - 1; i++) {
            set<vector<int>> tails = build(nums, i + 1);
            for (auto tail: tails) {
                s.insert(tail);
                
                if (head <= tail[0]) {
                    vector<int> newSubsequence = vector<int>(tail);
                    newSubsequence.insert(newSubsequence.begin(), 1, head);
                    s.insert(newSubsequence);
                }
            }
            
        }
        
        return s;
    }  
};

class WASolution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {        
        vector<vector<int>> answer;
        set<vector<int>> subsequences = build(nums);
        for (vector<int> subsequence: subsequences) {
            if (subsequence.size() >= 2) {
                answer.push_back(subsequence);
            }
        }
        return answer;
    }
    
private:
    set<vector<int>> build(vector<int>& nums) {
        set<vector<int>> s;
        if (nums.size() == 0) {
            return s;
        }
        
        if (nums.size() == 1) {
            s.insert({nums[0]});
            return s;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            int head = nums[i];
            auto newNums = without(nums, i);
            set<vector<int>> tails = build(newNums);
            for (auto tail: tails) {
                s.insert(tail);
                
                if (head <= tail[0]) {
                    vector<int> newSubsequence = vector<int>(tail);
                    newSubsequence.insert(newSubsequence.begin(), 1, head);
                    s.insert(newSubsequence);
                }
            }
            
        }
        
        return s;
    }  
    
    vector<int> without(vector<int>& nums, int withoutIdx) {
        vector<int> newNums;
        for (int i = 0; i < nums.size(); i++) {
            if (i != withoutIdx) {
                newNums.push_back(nums[i]);
            }
        }
        return newNums;
    }
};

int main() {
    Solution soln;
    // vector<int> nums = {52,183,124,154,-170,-191,-240,107,-178,171,75,186,-125,61,-298,284,21,-73,-294,253,146,248,-248,127,26,289,118,-22,-300,26,-116,-113,-44,29,252,-278,47,254,-106,246,-275,42,257,15,96,-298,-69,-104,-239,-95,-4,76,-202,156,-14,-178,188,-84,78,-195,-125,28,109,125,-25,-53,58,287,55,-296,198,281,53,-160,146,298,25,-41,-3,27,-242,169,287,-281,19,91,213,115,211,-218,124,-25,-272,278,296,-177,-166,-192,97,-49,-25,168,-81,6,-94,267,293,146,-1,-258,256,283,-156,197,28,78,267,-151,-230,-66,100,-94,-66,-123,121,-214,-182,187,65,-186,215,273,243,-99,-76,178,59,190,279,300,217,67,-117,170,163,153,-37,-147,-251,296,-176,117,68,258,-159,-300,-36,-91,-60,195,-293,-116,208,175,-100,-97,188,79,-270,80,100,211,112,264,-217,-142,5,105,171,-264,-247,138,275,227,-86,30,-219,153,10,-66,267,22,-56,-70,-234,-66,89,182,110,-146,162,-48,-201,-240,-225,-15,-275,129,-117,28,150,84,-264,249,-85,70,-140,-259,26,162,5,-203,143,184,101,140,207,131,177,274,-178,-79,14,-36,104,52,31,257,273,-52,74,276,104,-133,-255,188,-252,229,200,-74,-39,-250,142,-201,-196,-43,-40,255,-149,-299,-197,-175,-96,-155,-196,-24,12,79,71,-144,-59,-120,227,-256,-163,-297,116,286,-283,-31,-221,-41,121,-170,160,205,8,88,25,-272,-107,292,-180,299,94,-97,-81,-134,37,238};
    // vector<int> nums = {-2};
    vector<int> nums = {4,6,7,7};
    auto answer = soln.findSubsequences(nums);
    
    cout << endl;
    return 0;
}