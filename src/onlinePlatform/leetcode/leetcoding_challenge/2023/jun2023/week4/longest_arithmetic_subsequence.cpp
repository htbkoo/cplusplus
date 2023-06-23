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
    int longestArithSeqLength(vector<int>& nums) {
        if (nums.size() < 2) {
            // TODO: confirm this
            return nums.size();
        }
        
        unordered_map<int, unordered_map<int, int>> mapping;
        unordered_map<int, int> counts;
        counts[nums[0]]++;
        
        int answer = 2;
        
        for (int j = 1; j < nums.size(); ++j) {
            counts[nums[j]]++;
            answer = max(answer, counts[nums[j]]);

            for (int i = 0; i < j; ++i) {
                int diff = nums[i] - nums[j];
                if (diff == 0) {
                    continue;
                }

                if (mapping[diff].count(nums[j]) == 0) {
                    mapping[diff][nums[j]] = 0;
                }

                if (mapping[diff].count(nums[i]) > 0) {
                    mapping[diff][nums[j]] = max(
                        mapping[diff][nums[j]],
                        mapping[diff][nums[i]] + 1
                    );
                } else {
                    mapping[diff][nums[j]] = 2;
                }

                answer = max(answer, mapping[diff][nums[j]]);
            }
        }
        
        return answer;
    }
};

class WASolution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        if (nums.size() < 2) {
            // TODO: confirm this
            return nums.size();
        }
        
        unordered_map<int, unordered_map<int, int>> mapping;
        
        int answer = 2;
        
        for (int j = 1; j < nums.size(); ++j) {
            for (int i = 0; i < j; ++i) {
                int diff = nums[i] - nums[j];
                if (mapping[diff].count(nums[i]) > 0) {
                    mapping[diff][nums[j]] = max(
                        mapping[diff][nums[j]],
                        mapping[diff][nums[i]] + 1
                    );
                } else {
                    mapping[diff][nums[j]] = 2;
                }
                
                answer = max(answer, mapping[diff][nums[j]]);
            }
        }
        
        return answer;
    }
};

int main() {
    Solution soln;

    vector<int> nums = {214,450,10,56,35,16,45,347,375,208,398,46,284,489,415,380,409,106,30,66,39,411,410,201,105,345,136,76,327,451,71,328,496,248,425,97,76,193,391,429,191,36,407,172,90,163,309,37,403,156,257,77,338,457,445,357,142,493,500,165,440,154,88,193,359,296,70,97,364,84,395,240,2,74,219,277,447,149,3,297,40,196,96,161,147,106,27,429,348,436,42,494,371,331,104,10,283,415,444,126,476,392,25,437,167,148,251,275,94,52,325,459,353,247,266,129,479,363,493,375,110,420,430,97,84,31,118,150,164,188,456,117,158,144,482,150,179,6,164,73,438,295,123,2,402,111,182,161,350,260,486,18,285,485,281,131,486,121,116,253,323,423,47,328,139,169,32,148,256,397,267,484,312,50,123,250,416,390,445,87,281,174,93,15,293,471,103,280,42,147,111,194,188,338,396,340,500,92,240,480,153,162,206,277,208,401,414,60,257,167,419,175,175,100,314,449,469,246,412,424,52,303,83,9,30,4,245,106,91,354,90,347,460,208,217,197,480,412,288,222,182,443,19,454,91,74,136,309,236,412,8,64,422,87,54,330,276,256,12,180,340,144,487,302,418,130,50,446,487,169,204,403,229,63,399,430,272,473,370,456,415,384,418,149,22,15,364,173,213,84,185,236,11,353,433,345,25,413,200,107,369,193,68,300,199,450,490,230,141,112,154,43,490,206,11,55,204,318,373,180,253,357,486,441,180,441,459,47,387,213,120,462,301,21,139,306,497,264,342,446,311,305,448,21,279,471,496,419,462,358,216,490,237,312,159,90,34,36,352,119,372,290,42,114,162,3,369,122,127,236,464,10,204,225,219,221,443,101,15,263,313,498,164,451,387,217,364,316,371,263,380,96,30,65,417,290,451,207,351,317,457,366,350,2,414,375,177,447,409,272,252,486,156,87,200,116,201,498,342,98,67,279,466,271,75,161,492,237,481,356,403,64,473,362,56,466,175,99,197,308,327,413,343,474,446,76,375,68,479,490,167,339,249,419,424,355,101,371,84,86,270,335,244,293,75,121,118,89,171,197,221,15,234,402,239,225,475,426,337,92,432,253,210,163,251,219,440,492,280,317,336,148,302,276,353,446,448,83,444,304,244,169,45,65,202,62,318,457,431,161,471,54,288,150,280,159,376,169,115,458,371,458,446,146,232,153,487};

    cout << soln.longestArithSeqLength(nums) << endl;

    return 0;
}