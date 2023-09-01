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
    vector<int> countBits(int n) {
        vector<int> answer = {0};
        for (int i = 1; i <= n; ++i) {
            int add = (i % 2 == 1) ? 1 : 0;
            int prev = answer[i / 2];
            
            answer.push_back(prev + add);
        }
        return answer;
    }
};

class FirstSolution {
public:
    vector<int> countBits(int n) {
        vector<int> answer;
        for (int i = 0; i <= n; ++i) {
            answer.push_back(getNumBits(i));
        }
        return answer;
    }
    
private:
    int getNumBits(int i) {
        int count = 0;
        while (i > 0) {
            if (i % 2 == 1) {
                count++;
            }
            i /= 2;
        }
        return count;
    }
};