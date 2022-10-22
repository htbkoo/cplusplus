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
    string minWindow(string s, string t) {
        unordered_map<char, int> counterT;
        for (char ch: t) {
            if (counterT.count(ch) == 0) {
                counterT[ch] = 0;
            }
            counterT[ch]++;
        }
        
        string answer = "";
        unordered_map<char, int> counterS;                
        int left = 0;
        int right = -1;
        while (left < s.size()) {
            // TODO: confirm what if there are multiple answer?
            if (isAllIncluded(counterS, counterT)) {
                int len = right - left + 1;
                if (answer == "" || len < answer.size()) {
                    answer = s.substr(left, len);                    
                }
            
                counterS[s[left]]--;                
                left++;
            } else {
                right++;
                if (right >= s.size()) {
                    break;
                }
                counterS[s[right]]++;
            }
        }
        return answer;
    }

private:
    bool isAllIncluded(unordered_map<char, int> &counterS, unordered_map<char, int> &counterT) {
        for (auto &[ch, count]: counterT) {
            if (counterS.count(ch) == 0 || counterS[ch] < count) {
                return false;
            }
        }
        return true;    
    }
};

int main() {
    Solution soln;
    cout << soln.minWindow("ADOBECODEBANC", "ABC") << endl;
}