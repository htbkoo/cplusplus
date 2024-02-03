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

const int UNINITIALIZED = -1;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memo = vector<int>(arr.size(), UNINITIALIZED);
        return findMax(arr, 0, k);
    }

private:
    vector<int> memo;

    int findMax(vector<int>& arr, int i, int k) {
        if (i >= arr.size()) {
            return 0;
        }

        if (memo[i] == UNINITIALIZED) {
            int largest = arr[i];
            for (int j = 0; j < k; j++) {
                if ((i + j) >= arr.size()) {
                    break;
                }

                largest = max(largest, arr[i + j]);
                int count = j + 1;
                int nextI = i + j + 1;

                memo[i] = max(
                    memo[i],
                    largest * count + findMax(arr, nextI, k)
                );
            }
        }

        return memo[i];
    }
};