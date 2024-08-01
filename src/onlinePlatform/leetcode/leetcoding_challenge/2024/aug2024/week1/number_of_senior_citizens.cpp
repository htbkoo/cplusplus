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
    int countSeniors(vector<string>& details) {
        int PHONE_NUMBER_SIZE = 10;
        int GENDER_SIZE = 1;
        int AGE_SIZE = 2;
        
        int AGE_THRESHOLD = 60;
        
        int answer = 0;
        
        for (auto detail: details) {            
            auto ageStr = detail.substr(PHONE_NUMBER_SIZE + GENDER_SIZE, AGE_SIZE);
            auto age = stoi(ageStr);
            
            if (age > AGE_THRESHOLD) {
                answer++;
            }
        }
        
        return answer;
    }
};