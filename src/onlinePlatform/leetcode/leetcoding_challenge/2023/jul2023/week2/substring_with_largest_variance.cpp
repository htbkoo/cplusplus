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
    int largestVariance(string s) {
        chSet = unordered_set<char>();
        for (auto ch: s) {
            chSet.insert(ch);
        }
        
        string reversedS(s);
        reverse(reversedS.begin(), reversedS.end());
            
        return max(findLargestVariance(s), findLargestVariance(reversedS));
    }
    
private:
    unordered_set<char> chSet;
    int findLargestVariance(string s) {
        int answer = 0;
        int diff = 0;
        bool hasCh2 = false;
        for (auto ch1: chSet) {
            for (auto ch2: chSet) {
                if (ch1 == ch2) {
                    continue;
                }

                diff = 0;
                hasCh2 = false;
                for (auto ch: s) {
                    if (ch == ch1) {
                        diff++;
                    } else if (ch == ch2) {
                        diff--;
                        hasCh2 = true;
                        if (diff < 0) {
                            diff = 0;
                            hasCh2 = false;                            
                        }
                    }
                    
                    if (hasCh2) {
                        answer = max(answer, diff);
                    }
                }
            }
        }
        
        return answer;
    }
};

int main() {
    Solution soln;

    cout << soln.largestVariance("aababbb") << endl;
    
    return 0;
}