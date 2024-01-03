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
    int numberOfBeams(vector<string>& bank) {
        int answer = 0;
        int prev = 0;

        for (int i = 0; i < bank.size(); ++i) {
            int count = getCount(i, bank);
            if (count > 0) {
                answer += count * prev;
                prev = count;
            }
        }

        return answer;
    }

private:
    int getCount(int i, vector<string>& bank) {
        // TODO: validate 0 <= i < bank.size()

        int count = 0;
        for (auto ch: bank[i]) {
            if (ch == '1') {
                count++;
            }
        }

        return count;
    }
};
