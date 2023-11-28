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
    int numberOfWays(string corridor) {
        const int NO_WAY = 0;
        const int MOD = 1e9 + 7;

        long answer = 1;

        long numPlants = 0;
        long numSeats = 0;

        for (auto ch: corridor) {
            switch (ch) {
                case 'S':
                    numSeats++;

                if (numSeats > 2 && numSeats % 2 != 0) {
                    answer = (answer * (numPlants + 1)) % MOD;
                    numPlants = 0;
                }

                break;
                case 'P':
                    if (numSeats >= 2 && numSeats % 2 == 0) {
                        numPlants++;
                    }
                break;
            }
        }

        if (numSeats == 0 || numSeats % 2 != 0) {
            return NO_WAY;
        }

        return answer;
    }
};