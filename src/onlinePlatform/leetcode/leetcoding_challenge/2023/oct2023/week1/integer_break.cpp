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
    int integerBreak(int n) {
        memo = unordered_map<int, int>();
        
        int answer = 0;
        for (int i = 1; i < n; ++i) {
            answer = max(answer, i * b(n - i));
        }
        
        return answer;
    }

private:
    unordered_map<int, int> memo;
    
    int b(int n) {
        if (n == 1) {
            return 1;
        }
        
        if (memo.count(n) == 0) {
            memo[n] = n;
            for (int i = 1; i < n; ++i) {
                memo[n] = max(memo[n], i * b(n - i));
            }
        }
        
        return memo[n];
    }

};
