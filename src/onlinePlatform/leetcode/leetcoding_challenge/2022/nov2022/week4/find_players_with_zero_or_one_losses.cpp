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
#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> loses;
        
        for (auto& match: matches) {
            int win = match[0], lose = match[1];
            if (loses.count(win) == 0) {
                loses[win] = 0;
            }
            loses[lose]++;
        }
        
        vector<vector<int>> answer = {{}, {}};
        for (auto& [player, countLose]: loses) {
            if (countLose == 0)  {
                answer[0].push_back(player);
            } else if (countLose == 1)  {
                answer[1].push_back(player);
            }
        }
        
        for (vector<int>& v: answer) {
            sort(v.begin(), v.end());
        }
        
        return answer;
    }
};

class WASolution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> count;
        unordered_map<int, int> wins;
        unordered_map<int, int> loses;
        
        for (auto& match: matches) {
            int win = match[0], lose = match[1];
            for (unordered_map<int, int> m: {count, wins, loses}) {
                if (m.count(win) == 0) {
                    m[win] = 0;
                }
                if (m.count(lose) == 0) {
                    m[lose] = 0;
                }
            }
            
            count[win]++;
            count[lose]++;
            
            wins[win]++;
            loses[lose]++;
        }
        
        vector<vector<int>> answer = {{}, {}};
        for (auto& [player, countLose]: loses) {
            if (countLose == 0)  {
                answer[0].push_back(player);
            } else if (countLose == 1)  {
                answer[1].push_back(player);
            }
        }
        
        for (vector<int>& v: answer) {
            sort(v.begin(), v.end());
        }
        
        return answer;
    }
};

int main() {
    Solution soln;
    vector<vector<int>> matches = {{1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}};
    // cout << soln.findWinners(matches) << endl;
    soln.findWinners(matches);
    return 0;
}