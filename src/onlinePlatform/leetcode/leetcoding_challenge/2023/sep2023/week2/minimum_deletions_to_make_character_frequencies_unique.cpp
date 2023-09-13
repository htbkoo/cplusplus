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
    int minDeletions(string s) {
        unordered_map<char, int> counter;
        for (char ch: s) {
            counter[ch]++;
        }
        
        unordered_map<int, int> freqCounter;
        int maxCount = 0;
        for (auto &[ch, count]: counter) {
            freqCounter[count]++;
            maxCount = max(maxCount, count);
        }
        
        int answer = 0;
        int currCount = 0;
        for (int count = maxCount; count > 0; --count) {
            currCount += freqCounter[count];
            
            if (currCount >= 1) {
                currCount--;
                answer += currCount;
            }

        }
        
        return answer;
    }
};

class WASolution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> counter;
        for (char ch: s) {
            counter[ch]++;
        }
        
        // set<int> allCountsSet;
        unordered_map<int, int> freqCounter;
        int maxCount = 0;
        for (auto &[ch, count]: counter) {
            freqCounter[count]++;
            // allCountsSet.insert(count);
            maxCount = max(maxCount, count);
        }
        
        // vector<int> allCounts(allCountsSet.begin(), allCountsSet.end());
        
        int answer = 0;
        int currCount = 0;
        for (int count = maxCount; count >= 0; --count) {
            currCount += freqCounter[count];
            
            if (currCount >= 1) {
                currCount--;
                answer += currCount;
            }
        }
        
        return answer;
    }
};

int main() {
    Solution soln;

    cout << soln.minDeletions("bbcebab") << endl;

    return 0;
}