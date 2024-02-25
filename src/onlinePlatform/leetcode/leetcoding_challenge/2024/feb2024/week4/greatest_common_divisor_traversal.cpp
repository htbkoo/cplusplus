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
const int LARGEST_NUM = 1e5;

vector<int> primes;
vector<int> isPrimes(LARGEST_NUM + 1, false);

for (int i = 2; i <= LARGEST_NUM; ++i) {
    isPrimes[i] = true;
    for (auto p: primes) {
        if (i % p == 0) {
            isPrimes[i] = false;
            break;
        }
        if (p * p > i) {
            break;
        }
    }

    if (isPrimes[i]) {
        primes.push_back(i);
    }
}


class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            parents.push_back(i);
        }
        sizes = vector<int>(nums.size(), 1);

        int largest = *max_element(begin(nums), end(nums));
        for (auto p: primes) {
            if (p > largest) {
                break;
            }

            int rep = -1;

            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] % p == 0) {
                    if (rep == -1) {
                        rep = i;
                    }
                    unionSets();
                }
            }
        }

    }

private:
    vector<int> parents;
    vector<int> sizes;


};