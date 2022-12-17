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
    int evalRPN(vector<string>& tokens) {
        vector<long> stack;
        for (string token: tokens) {
            if (isOperator(token)) {
                long num2 = popBack<long>(stack);
                long num1 = popBack<long>(stack);
                long result = evaluate(token, num1, num2);
                stack.push_back(result);
            } else {
                stack.push_back(stoi(token));
            }
        }
        return stack[0];
    }
    
private:
    bool isOperator(string token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }
    
    long evaluate(string token, long num1, long num2) {
        if (token == "+") {
            return num1 + num2;
        } else if (token == "-") {
            return num1 - num2;
        } else if (token == "*") {
            return num1 * num2;
        } else if (token == "/") {
            return num1 / num2;
        } else {
            throw invalid_argument("unknown operator: " + token);
        }
    }
    
    template <typename T>
    T popBack(vector<T>& stack) {
        T value = stack.back();
        stack.pop_back();
        return value;
    }
};

int main() {
    Solution soln;
    // vector<string> tokens = {"2","1","+","3","*"};
    vector<string> tokens = {"4","3","-"};
    cout << soln.evalRPN(tokens) << endl;
}