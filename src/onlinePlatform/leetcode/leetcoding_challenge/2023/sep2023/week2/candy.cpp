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
    int candy(vector<int>& ratings) {
        vector<pair<int, int>> ratingsWithIdx;
        for (int i = 0; i < ratings.size(); ++i) {
            ratingsWithIdx.push_back(pair{ratings[i], i});
        }
        
        std::priority_queue pq(ratingsWithIdx.begin(), ratingsWithIdx.end(), std::greater<pair<int, int>>());
        
        vector<int> candies(ratings.size(), 0);
        
        while (pq.size() > 0) {
            auto [_, idx] = pq.top();
            pq.pop();
            
            candies[idx] = 1;
            if (idx > 0 && ratings[idx] > ratings[idx - 1]) {
                candies[idx] = max(
                    candies[idx],
                    candies[idx - 1] + 1
                );
            }
            if (idx < ratings.size() - 1 && ratings[idx] > ratings[idx + 1]) {
                candies[idx] = max(
                    candies[idx],
                    candies[idx + 1] + 1
                );
            }
        }
        
        int answer = 0;
        for (auto candy: candies) {
            answer += candy;
        }
        
        return answer;
    }
};
