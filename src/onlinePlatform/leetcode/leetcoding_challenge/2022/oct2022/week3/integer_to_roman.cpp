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
    string intToRoman(int num) {
        string answer;
        while (num > 0) {
            // TODO: how do we represent num >= 4000?
            if (num >= 1000) {
                answer += "M";
                num -= 1000;
            } else if (num >= 900) {
                answer += "CM";
                num -= 900;
            } else if (num >= 500) {
                answer += "D";
                num -= 500;
            } else if (num >= 400) {
                answer += "CD";
                num -= 400;
            } else if (num >= 100) {
                answer += "C";
                num -= 100;
            } else if (num >= 90) {
                answer += "XC";
                num -= 90;
            } else if (num >= 50) {
                answer += "L";
                num -= 50;
            } else if (num >= 40) {
                answer += "XL";
                num -= 40;
            } else if (num >= 10) {
                answer += "X";
                num -= 10;
            } else if (num >= 9) {
                answer += "IX";
                num -= 9;
            } else if (num >= 5) {
                answer += "V";
                num -= 5;
            } else if (num >= 4) {
                answer += "IV";
                num -= 4;
            } else {
                answer += "I";
                num -= 1;                
            }
        }
            
        return answer;
    }
};