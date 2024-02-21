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
    int rangeBitwiseAnd(int left, int right) {
        vector<int> bitsLeft = asBits(left);
        vector<int> bitsRight = asBits(right);
        vector<int> bitsAnswer(32, 0);

        for (int i = 0; i < bitsAnswer.size(); ++i) {
            if (bitsLeft[i] == 1 && bitsRight[i] == 1) {
                bitsAnswer[i] = 1;
            } else {
                if (bitsLeft[i] != bitsRight[i]) {
                    break;
                }
            }
        }

        long answer = 0;
        long base = 1;
        for (int i = bitsAnswer.size() - 1; i >= 0; --i) {
            if (bitsAnswer[i] == 1) {
                answer += base;
            }
            base *= 2;
        }

        return answer;
    }

private:
    vector<int> asBits(int num) {
        vector<int> bits(32, 0);

        int i = bits.size() - 1;
        while (num > 0) {
            if (num % 2 == 1) {
                bits[i] = 1;
            }
            num /= 2;
            i -= 1;
        }

        return bits;
    }
};

class WASolution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // if (left == right) {
        //     return left;
        // }

        vector<int> bitsLeft = asBits(left);
        vector<int> bitsRight = asBits(right);
        vector<int> bitsAnswer(32, 0);

        bool started = false;
        for (int i = 0; i < bitsAnswer.size(); ++i) {
            if (bitsLeft[i] == 1 && bitsRight[i] == 1) {
                started = true;
                bitsAnswer[i] = 1;
            } else {
                if (started || bitsLeft[i] == 1 || bitsRight[i] == 1) {
                    break;
                }
            }
        }

        long answer = 0;
        long base = 1;
        for (int i = bitsAnswer.size() - 1; i >= 0; --i) {
            if (bitsAnswer[i] == 1) {
                answer += base;
            }
            base *= 2;
        }

        return answer;
    }

private:
    vector<int> asBits(int num) {
        vector<int> bits(32, 0);

        int i = bits.size() - 1;
        while (num > 0) {
            if (num % 2 == 1) {
                bits[i] = 1;
            }
            num /= 2;
            i -= 1;
        }

        return bits;
    }
};

int main () {
    Solution soln;
    // cout << ((int) pow(2, 2)) << endl;
    cout << soln.rangeBitwiseAnd(5, 5) << endl;

    return 0;
}