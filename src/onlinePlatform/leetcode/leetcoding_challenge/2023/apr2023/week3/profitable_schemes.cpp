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

const int MAX_CRIME_COUNT = 100;
const int MAX_MEMBER_COUNT = 100;
const int MAX_PROFIT = 100;
const int UNINITIALIZED = -1;

class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(memo, UNINITIALIZED, sizeof(memo));
        
        return count(n, minProfit, 0, group, profit);
    }
    
private:
    int MOD = 1e9 + 7;
    int memo[MAX_MEMBER_COUNT + 1][MAX_PROFIT + 1][MAX_CRIME_COUNT + 1];
    
    int count(int remainN, int remainProfit, int i, vector<int>& group, vector<int>& profit) {
        if (memo[remainN][remainProfit][i] != UNINITIALIZED) {
            return memo[remainN][remainProfit][i];
        } 
        
        if (i >= group.size()) {
            if (remainProfit <= 0) {
                return 1;
            } else {
                return 0;
            }
        } 
        
        memo[remainN][remainProfit][i] = count(remainN, remainProfit, i + 1, group, profit);
        
        if (remainN >= group[i]) {
            int newRemainProfit = max(0, remainProfit - profit[i]);
            memo[remainN][remainProfit][i] = (
                memo[remainN][remainProfit][i]
                + count(remainN - group[i], newRemainProfit, i + 1, group, profit)
            ) % MOD;
        }
        
        return memo[remainN][remainProfit][i];
    }
};

class TLESolution2 {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memo = unordered_map<string, long long>();
        
        return count(n, minProfit, 0, group, profit);
    }
    
private:
    long long MOD = pow(10, 9) + 7;
    unordered_map<string, long long> memo;
    
    long long count(int remainN, int remainProfit, int i, vector<int>& group, vector<int>& profit) {
        string key = to_string(remainN) + "_" + to_string(remainProfit) + "_" + to_string(i);
        
        if (memo.count(key) > 0) {
            return memo[key];
        }
        
        if (i >= group.size()) {
            if (remainProfit <= 0) {
                return 1;
            } else {
                return 0;
            }
        } 
        
        if (remainN < 0) {
            return 0;
        }
        
        memo[key] = count(remainN, remainProfit, i + 1, group, profit);
        
        if (remainN >= group[i]) {            
            bool isProfitable = profit[i] >= remainProfit;
            
            if (isProfitable) {
                memo[key] = (memo[key] + count(remainN - group[i], -1, i + 1, group, profit)) % MOD;
            } else {
                memo[key] = (memo[key] + count(remainN - group[i], remainProfit - profit[i], i + 1, group, profit)) % MOD;
            }
            
        }
        
        return memo[key];
    }
};

class TLESolution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memo = unordered_map<string, long long>();
        
        return count(n, minProfit, 0, group, profit);
    }
    
private:
    long long MOD = pow(10, 9) + 7;
    unordered_map<string, long long> memo;
    
    long long count(int remainN, int remainProfit, int i, vector<int>& group, vector<int>& profit) {
        string key = to_string(remainN) + "_" + to_string(remainProfit) + "_" + to_string(i);
        
        if (memo.count(key) > 0) {
            return memo[key];
        }
        
        if (i >= group.size() || remainN < 0) {
            return 0;
        } 
        
        memo[key] = count(remainN, remainProfit, i + 1, group, profit);
        
        if (remainN >= group[i]) {
            bool isProfitable = profit[i] >= remainProfit;
            
            if (isProfitable) {
                memo[key] = (1 + memo[key] + count(remainN - group[i], -1, i + 1, group, profit)) % MOD;
            } else {
                memo[key] = (memo[key] + count(remainN - group[i], remainProfit - profit[i], i + 1, group, profit)) % MOD;
            }
            
        }
        
        return memo[key];
    }
};