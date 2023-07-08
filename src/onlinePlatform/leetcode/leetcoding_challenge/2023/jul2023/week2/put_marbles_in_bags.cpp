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
    long long putMarbles(vector<int>& weights, int k) {
        vector<long long> combined;
        for (int i = 1; i < weights.size(); ++i) {
            combined.push_back(weights[i - 1] + weights[i]);
        }
        sort(combined.begin(), combined.end());
        
        long long answer = 0;
        for (int i = 0; i < k - 1; ++i) {
            answer += combined[combined.size() - 1 - i] - combined[i];
        }
        
        return answer;
    }
};