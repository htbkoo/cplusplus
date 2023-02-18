#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        long long totalNegative = 0;        
        for (auto transaction: transactions) {
            int cost = transaction[0], cashback = transaction[1];            
            long long diff = cashback - cost;            
            if (diff < 0) {
                totalNegative += diff;
            }            
        }
        
        long long answer = 0;
        for (auto transaction: transactions) {
            int cost = transaction[0], cashback = transaction[1];            
            long long diff = cashback - cost;            
            if (diff < 0) {
                answer = min(answer, totalNegative - diff - cost);
            } else {
                answer = min(answer, totalNegative - cost);
            }
            
        }
        
        return -answer;
    }
};