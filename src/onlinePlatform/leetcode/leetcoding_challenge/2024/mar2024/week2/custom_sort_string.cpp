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
    string customSortString(string order, string s) {
        unordered_map<char, int> indices;
        for (auto ch: s) {
            indices[ch] = -1;
        }
        for (int i = 0; i < order.size(); ++i) {
            char ch = order[i];
            indices[ch] = i;
        }

        sort(begin(s), end(s), [&](char a, char b){ cout << a << " " << indices[a] << endl; return indices[a] < indices[b]; });

        return s;
    }
};

class FirstSolution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> counter;
        for (auto ch: s) {
            counter[ch]++;
        }

        string answer;
        for (auto ch: order) {
            for (int i = 0; i < counter[ch]; ++i) {
                answer += ch;
            }
        }
        for (auto& [ch, count]: counter) {
            if (order.find(ch) == -1) {
                for (int i = 0; i < count; ++i) {
                    answer += ch;
                }
            }
        }

        return answer;
    }
};

int main () {
    Solution soln;

    cout << soln.customSortString("ba", "abababababaab") << endl;
    cout << soln.customSortString("bcafg", "abcd") << endl;

    return 0;
}