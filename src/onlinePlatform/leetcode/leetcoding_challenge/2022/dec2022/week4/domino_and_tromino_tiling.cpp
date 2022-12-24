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
    int numTilings(int n) {
        cache = unordered_map<string, long>();
        return count(n, 0, 0);
    }
    
private:
    const int MOD = 1000000007;
    const vector<pair<int, int>> SAME_CONFIGS = {
        pair{1, 1},
        pair{2, 2},
        pair{2, 1},
        pair{1, 2}
    };
    const vector<pair<int, int>> AT_MOST_ONE_CONFIGS = {
        pair{2, 1},
        pair{1, 2}
    };
    const vector<pair<int, int>> DIFF_CONFIGS = {
        pair{2, 0},
        pair{0, 2}
    };
    const string SEPARATOR = "_";
    unordered_map<string, long> cache;
    
    long count(int n, int up, int down) {
        if (up == n && down == n) {
            return 1;
        }
        if (up > n || down >= n) {
            return 0;
        }
        string key = getKey(up, down);
        if (cache.count(key) > 0) {
            return cache[key];
        }
        cache[key] = 0;
        if (up == down) {
            for (auto& [du, dd]: SAME_CONFIGS) {
                cache[key] = (cache[key] + count(n, up + du, down + dd)) % MOD;
            }
        }

        if (up > down) {
            cache[key] = (cache[key] + count(n, up, down + 2)) % MOD;
            if (up - down == 1) {
                cache[key] = (cache[key] + count(n, up + 1, down + 2)) % MOD;
            }
        }

        if (down > up) {
            cache[key] = (cache[key] + count(n, up + 2, down)) % MOD;            
            if (down - up == 1) {
                cache[key] = (cache[key] + count(n, up + 2, down + 1)) % MOD;
            }
        }

        return cache[key] % MOD;
    }
    
    string getKey(int up, int down) {
        return to_string(up) + SEPARATOR + to_string(down);
    }
};

class WASolution {
public:
    int numTilings(int n) {
        cache = unordered_map<string, long>();
        return count(n, 0, 0);
    }
    
private:
    const int MOD = 1000000007;
    const vector<pair<int, int>> CONFIGS = {
        pair{1, 1},
        pair{2, 0},
        pair{0, 2},
        pair{2, 1},
        pair{1, 2}
    };
    const string SEPARATOR = "_";
    unordered_map<string, long> cache;
    
    long count(int n, int up, int down) {
        if (up == n && down == n) {
            return 1;
        }
        if (up >= n || down >= n) {
            return 0;
        }
        string key = getKey(up, down);
        if (cache.count(key) > 0) {
            return cache[key];
        }
        cache[key] = 0;
        for (auto& [du, dd]: CONFIGS) {
            cache[key] = (cache[key] + count(n, up + du, down + dd)) % MOD;
        }
        return cache[key] % MOD;
    }
    
    string getKey(int up, int down) {
        return to_string(up) + SEPARATOR + to_string(down);
    }
};

int main() {
    Solution soln;
    // cout << soln.numTilings(2) << endl;
    cout << soln.numTilings(5) << endl;
}