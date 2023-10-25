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
    int kthGrammar(int n, int k) {
        k -= 1;
        vector<int> bits;
        for (int i = 1; i < n; ++i) {
            bits.push_back(k % 2);
            k /= 2;
        }
        
        int answer = 0;
        while (bits.size() > 0) {
            int b = bits.back();
            bits.pop_back();
            if (b == 1) {
                answer = 1 - answer;
            }
        }
        return answer;
    }
};

class WASolution {
public:
    int kthGrammar(int n, int k) {
        k -= 1;
        vector<int> bits;
        while (k > 0) {
            bits.push_back(k % 2);
            k /= 2;
        }
        reverse(begin(bits), end(bits));
        
        int answer = 0;
        for (int b: bits) {
            if (b == 1) {
                answer = 1 - answer;
            }
        }
        return answer;
    }
};