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

void populatePrimes() {
    if (primes.size() > 0) {
        return;
    }
    for (int i = 2; i <= LARGEST_NUM; ++i) {
        bool isPrime = true;
        for (auto p: primes) {
            if (i % p == 0) {
                isPrime = false;
                break;
            }
            if (p * p > i) {
                break;
            }
        }

        if (isPrime) {
            primes.push_back(i);
        }
    }
}


class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        populatePrimes();

        unordered_set<int> numsSet(begin(nums), end(nums));
        nums = vector<int>(begin(numsSet), end(numsSet));

        for (int i = 0; i < nums.size(); ++i) {
            parents.push_back(i);
        }
        sizes = vector<int>(nums.size(), 1);

        int largestSetSize = 1;

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
                    largestSetSize = max(largestSetSize, unionSets(i, rep));
                }
            }
        }

        return largestSetSize == nums.size();
    }

private:
    vector<int> parents;
    vector<int> sizes;

    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }

    int unionSets(int x, int y) {
        x = find(x);
        y = find(y);

        if (x != y) {
            if (sizes[y] > sizes[x]) {
                int temp = y;
                y = x;
                x = temp;
            }

            parents[y] = x;
            sizes[x] += sizes[y];
        }

        return sizes[x];
    }
};

class TLESolution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        populatePrimes();

        for (int i = 0; i < nums.size(); ++i) {
            parents.push_back(i);
        }
        sizes = vector<int>(nums.size(), 1);

        int largestSetSize = 1;

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
                    largestSetSize = max(largestSetSize, unionSets(i, rep));
                }
            }
        }

        return largestSetSize == nums.size();
    }

private:
    vector<int> parents;
    vector<int> sizes;

    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }

    int unionSets(int x, int y) {
        x = find(x);
        y = find(y);

        if (x != y) {
            if (sizes[y] > sizes[x]) {
                int temp = y;
                y = x;
                x = temp;
            }

            parents[y] = x;
            sizes[x] += sizes[y];
        }

        return sizes[x];
    }
};