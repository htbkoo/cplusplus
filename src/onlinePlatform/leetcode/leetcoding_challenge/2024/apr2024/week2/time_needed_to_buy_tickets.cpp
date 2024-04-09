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
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        if (k >= tickets.size() || tickets[k] <= 0) {
            // TODO: confirm this
            return 0;
        } 
        
        int answer = 0;
        
        for (int i = 0; i < tickets.size(); ++i) {
            int maxTime = max(0, (i <= k) ? tickets[k] : (tickets[k] - 1));
             
            answer += min(maxTime, tickets[i]);
        }

        return answer;
    }
};

class FirstSolution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int answer = 0;
        
        while (tickets[k] > 0) {
            for (int i = 0; i < tickets.size(); ++i) {
                if (tickets[i] > 0) {
                    answer++;
                    tickets[i]--;
                }
                if (tickets[k] == 0) {
                    return answer;
                }
            }
        }
        
        return answer;
    }
};