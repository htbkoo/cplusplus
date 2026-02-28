#include <algorithm>
#include <bitset>
#include <cmath>
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
    int concatenatedBinary(int n) {
        int MOD = pow(10, 9) + 7;

        long answer = 0;
        for (int num = 1; num <= n; ++num) {
            auto num_bits = get_num_bits(num);
            answer = ((answer << num_bits) + num) % MOD;
        }

        return answer;
    }

    int get_num_bits(int num) {
        int num_bits = 0;
        while (num > 0) {
            num /= 2;
            num_bits++;
        }
        return num_bits;
    }
};


class TLESolution {
public:
    int concatenatedBinary(int n) {
        int NUM_BITS = 32;
        int MOD = pow(10, 9) + 7;

        long answer = 0;
        for (int num = 1; num <= n; ++num) {
            // string s = bitset<32>(num).to_string();
            auto s = to_binary(num);
            for (auto ch: s) {
                answer = (answer * 2l + static_cast<long>(ch - '0') % 2l) % MOD;
            }
        }

        return answer;
    }

    string to_binary(int num) {
        string ans = "";
        while (num > 0) {
            int rem = num % 2;
            if (rem == 0) {
                ans = "0" + ans;
            } else {
                ans = "1" + ans;
            }
            num /= 2;
        }
        return ans;
    }
};

int main() {
    Solution soln;
    cout << soln.concatenatedBinary(12) << endl;
    return 0;
}
