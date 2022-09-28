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
#include <string>
#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text

class Solution {
public:
    string pushDominoes(string dominoes) {
        if (dominoes.size() == 0) {
            return dominoes;
        }

        int MOST_POSITIVE_NUM = numeric_limits<int>::max();

        vector<int> right = vector<int>(dominoes.size());
        if (dominoes[0] == 'R') {
            right[0] = 0;
        } else {
            right[0] = MOST_POSITIVE_NUM;
        }
        for (int i = 1; i < dominoes.size(); i++) {
            switch (dominoes[i]) {
                case 'L':
                    right[i] = MOST_POSITIVE_NUM;
                    break;
                case 'R':
                    right[i] = 0;
                    break;
                case '.':
                    if (right[i - 1] < MOST_POSITIVE_NUM) {
                        right[i] = right[i - 1] + 1;
                    } else {
                        right[i] = MOST_POSITIVE_NUM;
                    }
                    break;
                default: {
                    throw invalid_argument("invalid dominoes: " + dominoes);
                }
             }
        }

        vector<int> left = vector<int>(dominoes.size());
        if (dominoes[dominoes.size() - 1] == 'L') {
            left[dominoes.size() - 1] = 0;
        } else {
            left[dominoes.size() - 1] = MOST_POSITIVE_NUM;
        }
        for (int i = dominoes.size() - 2; i >= 0; i--) {
            switch (dominoes[i]) {
                case 'L':
                    left[i] = 0;
                    break;
                case 'R':
                    left[i] = MOST_POSITIVE_NUM;
                    break;
                case '.':
                    if (left[i + 1] < MOST_POSITIVE_NUM) {
                        left[i] = left[i + 1] + 1;
                    } else {
                        left[i] = MOST_POSITIVE_NUM;
                    }
                    break;
                default: {
                    throw invalid_argument("invalid dominoes: " + dominoes);
                }
             }
        }
        
        string answer = string(dominoes);
        for (int i = 0; i < dominoes.size(); i++) {
            if (left[i] == right[i]) {
                answer[i] = '.';
            } else if (left[i] < right[i]) {
                answer[i] = 'L';
            } else {
                answer[i] = 'R';
            }
        }

        return answer;
    }
};

int main() {
    Solution soln;
    
    cout << soln.pushDominoes(".L.R...LR..L..") << endl;

    return 0;
}