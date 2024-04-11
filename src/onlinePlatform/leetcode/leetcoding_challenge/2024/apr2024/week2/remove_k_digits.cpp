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
    string removeKdigits(string num, int k) {
        if (k >= num.size()) {
            return "0";
        }
        
        vector<int> stack;
        for (auto digit: num) {
            while (k > 0 && stack.size() > 0 && digit < stack.back()) {
                k--;
                stack.pop_back();
            }
            stack.push_back(digit);
        }
        
        while (k > 0) {
            k--;
            stack.pop_back();
        }
        
        string answer;
        for (auto digit: stack) {
            if (digit != '0' || answer.size() > 0) {
                answer += digit;
            }
        }
        
        // while (stack.size() > 0) {
        //     answer += stack.back();
        //     stack.pop_back();
        // }
        
        if (answer.size() == 0) {
            return "0";
        }
        
        return answer;
    }
};
