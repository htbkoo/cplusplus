#include <algorithm>
#include <cmath>
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
    int calculate(string s) {
        int i = 0;
        return _calculate(s, i);
    }
    
private:
    int _calculate(string& s, int& i) {
        vector<int> prevNums;
        vector<char> curr;
        int currSign = 1;
        
        while (i < s.size()) {
            char ch = s[i];
            switch (ch) {
                case ' ':
                    break;
                case '+':                    
                case '-':                    
//                     int currNum = 0;
//                     if (!curr.empty()) {
//                         currNum = atoi(string(curr.begin(), curr.end()));
//                         curr = vector<char>();
//                     }
//                     prev.push_back(currNum * currSign);
                    
                    if (!curr.empty()) {
                        int currNum = asInt(curr);
                        curr.clear();
                        prevNums.push_back(currNum * currSign);
                    }
                    
                    if (ch == '-') {
                        currSign = -1;
                    } else {
                        currSign = 1;
                    }
                    
                    break;
                    
//                 case '*':
//                 case '/':
//                     if (curr.empty()) {
//                         throw logic_error("no number before operator");
//                     }
//                     int currNum = atoi(string(curr.begin(), curr.end()));
//                     curr = vector<char>();
                    
//                     if (prev.empty()) {
//                         throw logic_error("state is empty before operator");
//                     }
                    
//                     int newNum;
//                     if (ch == '*') {
//                         newNum = prev.beck() * currNum;
//                     } else {
//                         newNum = prev.beck() / currNum;
//                     }
//                     prev.pop_back();
//                     prev.push_back(newNum);
                    
//                     break;
                case '(': {
                    i++;
                    int result = _calculate(s, i);
                    prevNums.push_back(result * currSign);
                    break;
                }
                case ')': {
                    return getSumWithCurr(prevNums, curr, currSign); 
                }
                default:
                    if (isDigit(ch)) {
                        curr.push_back(ch);
                        break;
                    }                    
                    throw invalid_argument("invalid string: " + s);
            }
            
            i++;
        }

        return getSumWithCurr(prevNums, curr, currSign); 
    }
    
    int getSumWithCurr(vector<int>& v, vector<char>& curr, int currSign) {
        int currNum = 0;
        if (!curr.empty()) {
            currNum = asInt(curr);            
        }
        
        return currNum * currSign + sum(v);
    }
    
    int sum(vector<int>& v) {
        int totalSum = 0;
        for (int num: v) {
            totalSum += num;
        }
        return totalSum;
    }
    
    int asInt(vector<char>& digits) {
        if (digits.empty()) {
            return 0;
        } else {            
            return stoi(string(digits.begin(), digits.end()));;
        }
    }
    
    bool isDigit(char ch) {
        return '0' <= ch && ch <= '9';
    }
};

int main() {
    Solution soln;
    cout << soln.calculate("(1+(4+5+2)-3)+(6+8)") << endl;
}