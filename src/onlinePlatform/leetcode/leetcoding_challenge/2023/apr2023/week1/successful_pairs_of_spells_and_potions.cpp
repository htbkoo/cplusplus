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
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<long long> potionsLL;
        for (auto potion: potions) {
            potionsLL.push_back((long long) potion);
        }
        
        vector<int> answers;
        for (auto spell: spells) {
            long long required = (success + (long long) spell - 1LL) / (long long) spell;
            int count = potionsLL.size() - (lower_bound(potionsLL.begin(), potionsLL.end(), required) - potionsLL.begin());
            answers.push_back(count);
            
        }
        
        return answers;
    }
};

class WASolution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        
        vector<int> answers;
        for (auto spell: spells) {
            int required = (success + (long long) spell - 1LL) / (long long) spell;
            int count = potions.size() - (lower_bound(potions.begin(), potions.end(), required) - potions.begin());
            answers.push_back(count);
            
        }
        
        return answers;
    }
};