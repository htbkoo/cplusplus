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

const int MOD = 1e9 + 7;
const int UNINITIALIZED = -1;

class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        memo = vector<vector<vector<int>>>();
        for (int i = 0; i <= n; ++i) {
            memo.push_back(vector<vector<int>>());
            for (int j = 0; j <= m; ++j) {
                memo.back().push_back(vector<int>(k + 1, UNINITIALIZED));
            }
        }
        
        return count(n, m, k, -1);
    }
    
private:
    vector<vector<vector<int>>> memo;
    
    int count(int remainN, int m, int remainK, int prevMax) {
        if (remainN == 0) {
            if (remainK == 0) {
                return 1;
            } else {
                return 0;
            }
        }
        
        if (remainK < 0) {
            return 0;
        }
        
        string key = to_string(remainN) + "_" + to_string(remainK) + "_" + to_string(prevMax);
        int mIdx = prevMax == -1 ? 0 : prevMax;
        if (memo[remainN][mIdx][remainK] == UNINITIALIZED) {
            memo[remainN][mIdx][remainK] = 0;
            for (int a = 1; a <= m; ++a) {
                int newK = remainK;
                if (a > prevMax) {
                    newK--;
                }
                memo[remainN][mIdx][remainK] = (memo[remainN][mIdx][remainK] + count(remainN - 1, m, newK, max(prevMax, a))) % MOD ;
            }
        }
        return memo[remainN][mIdx][remainK];
    }
};

class TLESolution {
public:
    int numOfArrays(int n, int m, int k) {
        memo = unordered_map<string, int>();
        return count(n, m, k, -1);
    }
    
private:
    unordered_map<string, int> memo;
    
    int count(int remainN, int m, int remainK, int prevMax) {
        if (remainN == 0) {
            if (remainK == 0) {
                return 1;
            } else {
                return 0;
            }
        }
        
        if (remainK < 0) {
            return 0;
        }
        
        string key = to_string(remainN) + "_" + to_string(remainK) + "_" + to_string(prevMax);
        if (memo.count(key) == 0) {
            memo[key] = 0;
            for (int a = 1; a <= m; ++a) {
                int newK = remainK;
                if (a > prevMax) {
                    newK--;
                }
                memo[key] = (memo[key] + count(remainN - 1, m, newK, max(prevMax, a))) % MOD ;
            }
        }
        return memo[key];
    }
};