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

const int MAX_NUM_LOCATIONS = 100;
const int MAX_FUEL = 200;
const int UNINITIALIZED = -1;
const int MOD = 1e9 + 7;

class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memo = vector<vector<int>>();
        for (int i = 0; i <= MAX_NUM_LOCATIONS; ++i) {
            memo.push_back(vector<int>(MAX_FUEL + 1, UNINITIALIZED));
        }
        return count(locations, start, finish, fuel);
    }
    
private:
    vector<vector<int>> memo;
    
    int count(vector<int>& locations, int city, int finish, int fuel) {
        if (fuel < 0) {
            return 0;
        }
        
        if (memo[city][fuel] != UNINITIALIZED) {
            return memo[city][fuel];
        }
        
        memo[city][fuel] = 0;
        if (city == finish) {
            memo[city][fuel] = (memo[city][fuel] + 1) % MOD;
        }

        for (int i = 0; i < locations.size(); ++i) {
            if (i != city) {
                // TODO: confirm if will underflow;
                int needFuel = abs(locations[i] - locations[city]);
                int addCount = count(locations, i, finish, fuel - needFuel);
                memo[city][fuel] = (memo[city][fuel] + addCount) % MOD;
            }
        }
        
        return memo[city][fuel];
    }
};