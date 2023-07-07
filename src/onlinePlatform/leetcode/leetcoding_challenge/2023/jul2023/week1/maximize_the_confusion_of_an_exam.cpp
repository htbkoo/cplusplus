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
    int maxConsecutiveAnswers(string answerKey, int k) {
        int answer = 0;
        
        int countT = 0;
        int countF = 0;
        
        int left = 0;
        
        for (int right = 0; right < answerKey.size(); right++) {
            char ch = answerKey[right];
            if (ch == 'T') {
                countT++;
            } else if (ch == 'F') {
                countF++;
            }
            // TODO: handle invalid input
                
            while (countT > k && countF > k) {
                char prevCh = answerKey[left];
                if (prevCh == 'T') {
                    countT--;
                } else if (prevCh == 'F') {
                    countF--;
                }
                left++;
            }
            
            answer = max(answer, right + 1 - left);
        }
        
        return answer;
    }
};