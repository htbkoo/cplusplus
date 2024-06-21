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
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();

        int alreadySatisfied = 0;
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0) {
                alreadySatisfied += customers[i];
            }
        }

        int best = 0;
        int curr = 0;
        for (int i = 0; i < min(n, minutes); ++i) {
            if (grumpy[i] == 1) {
                curr += customers[i];
                best = max(best, curr);
            }
        }

        for (int i = minutes; i < n; ++i) {
            int left = i - minutes;
            if (grumpy[left] == 1) {
                curr -= customers[left];
            }

            if (grumpy[i] == 1) {
                curr += customers[i];
            }

            best = max(best, curr);
        }

        return alreadySatisfied + best;
    }
};

class FirstSolution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();

        int alreadySatisfied = 0;
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0) {
                alreadySatisfied += customers[i];
            }
        }

        if (minutes >= n) {
            for (int i = 0; i < n; ++i) {
                if (grumpy[i] == 1) {
                    alreadySatisfied += customers[i];
                }
            }

            return alreadySatisfied;
        }

        int best = 0;
        int curr = 0;
        for (int i = 0; i < minutes; ++i) {
            if (grumpy[i] == 1) {
                curr += customers[i];
                best = max(best, curr);
            }
        }

        for (int i = minutes; i < n; ++i) {
            int left = i - minutes;
            if (grumpy[left] == 1) {
                curr -= customers[left];
            }

            if (grumpy[i] == 1) {
                curr += customers[i];
            }

            best = max(best, curr);
        }

        return alreadySatisfied + best;
    }
};
