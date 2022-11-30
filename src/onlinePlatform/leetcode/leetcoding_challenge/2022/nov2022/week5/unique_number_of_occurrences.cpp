#include <algorithm>
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
#include <random>
#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> counter;
        for (int i: arr) {
            counter[i]++;
        }
        
        unordered_set<int> appeared;
        for (auto& [_, count]: counter) {
            if (appeared.count(count) > 0) {
                return false;
            }
            appeared.insert(count);
        }
        
        return true;
    }
};