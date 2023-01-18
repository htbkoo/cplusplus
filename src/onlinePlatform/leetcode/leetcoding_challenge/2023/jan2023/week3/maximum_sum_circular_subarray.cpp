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
    int maxSubarraySumCircular(vector<int>& nums) {
        vector<int> numsNums = vector<int>(nums);
        for (int num: nums) {
            numsNums.push_back(num);
        }
        
        int left = 0;
        
        long answer = numeric_limits<long>::min();
        long currSum = 0;
        
        for (int right = 0; right < numsNums.size(); right++) {            
            int num = numsNums[right];
            
            if (currSum < 0) {
                currSum = num;
                left = right;
            } else {
                currSum += num;
            }
            
            while ((left < right) && (right - left + 1 > nums.size() || numsNums[left] <= 0)) {
                currSum -= numsNums[left];
                left++;
            }
                        
            answer = max(answer, currSum);
        }
        
        return answer;
    }
};

class WIPSolution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        long answer = numeric_limits<long>::min();
        long currSum = 0;
        
        for (int num: nums) {
            if (currSum < 0) {
                currSum = num;
            } else {
                currSum += num;
            }
            answer = max(answer, currSum);
        }
        
        return answer;
    }
};

int main() {
    Solution soln;
    vector<int> nums = {52,183,124,154,-170,-191,-240,107,-178,171,75,186,-125,61,-298,284,21,-73,-294,253,146,248,-248,127,26,289,118,-22,-300,26,-116,-113,-44,29,252,-278,47,254,-106,246,-275,42,257,15,96,-298,-69,-104,-239,-95,-4,76,-202,156,-14,-178,188,-84,78,-195,-125,28,109,125,-25,-53,58,287,55,-296,198,281,53,-160,146,298,25,-41,-3,27,-242,169,287,-281,19,91,213,115,211,-218,124,-25,-272,278,296,-177,-166,-192,97,-49,-25,168,-81,6,-94,267,293,146,-1,-258,256,283,-156,197,28,78,267,-151,-230,-66,100,-94,-66,-123,121,-214,-182,187,65,-186,215,273,243,-99,-76,178,59,190,279,300,217,67,-117,170,163,153,-37,-147,-251,296,-176,117,68,258,-159,-300,-36,-91,-60,195,-293,-116,208,175,-100,-97,188,79,-270,80,100,211,112,264,-217,-142,5,105,171,-264,-247,138,275,227,-86,30,-219,153,10,-66,267,22,-56,-70,-234,-66,89,182,110,-146,162,-48,-201,-240,-225,-15,-275,129,-117,28,150,84,-264,249,-85,70,-140,-259,26,162,5,-203,143,184,101,140,207,131,177,274,-178,-79,14,-36,104,52,31,257,273,-52,74,276,104,-133,-255,188,-252,229,200,-74,-39,-250,142,-201,-196,-43,-40,255,-149,-299,-197,-175,-96,-155,-196,-24,12,79,71,-144,-59,-120,227,-256,-163,-297,116,286,-283,-31,-221,-41,121,-170,160,205,8,88,25,-272,-107,292,-180,299,94,-97,-81,-134,37,238};
    cout << soln.maxSubarraySumCircular(nums) << endl;
    return 0;
}