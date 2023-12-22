#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int numOne = 0;
        for (int i = 0; i < s.size(); ++i) {
            auto ch = s[i];
            if (ch == '1') {
                numOne++;
            }
        }

        int answer = 0;
        int numZero = 0;
        for (int i = 0; i < s.size() - 1; ++i) {
            auto ch = s[i];
            if (ch == '0') {
                numZero++;
            } else if (ch == '1') {
                numOne--;
            }

            answer = max(
                answer,
                numZero + numOne
            );
        }

        return answer;
    }
};

int main() {
    Solution soln;
    cout << soln.maxScore("1111") << endl;
    return 0;
}
