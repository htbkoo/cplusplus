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
#include <string>
#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<int> ms;
        deque<pair<int, int>> dq;

        vector<vector<int>> answer;

        for (auto building: buildings) {
            int left = building[0], right = building[1], height = building[2];

            while (dq.size() > 0 && left >= dq[0].first) {
                auto &[prevRight, prevHeight] = dq[0];
                dq.pop_front();

                ms.erase(prevHeight);

                addToAnswer(answer, prevRight, ms);
            }

            dq.push_back(pair{right, height});
            ms.insert(height);
            addToAnswer(answer, left, ms);
        }

        while (dq.size() > 0) {
            auto &[prevRight, prevHeight] = dq[0];
            dq.pop_front();

            ms.erase(prevHeight);

            addToAnswer(answer, prevRight, ms);
        }

        return buildings;
    }

    void addToAnswer(vector<vector<int>>& answer, int x, multiset<int> ms) {
        int y = 0;
        if (ms.size() > 0) {
            y = *(ms.rbegin());
        }

        if (answer.size() == 0) {
            answer.push_back({x, y});
            return;
        }
        
        auto prevPoint = answer[answer.size() - 1];
        int prevX = prevPoint[0], prevY = prevPoint[1];

        if (prevX != x && prevY != y) {
            answer.push_back({x, y});
            return;
        }

        if (prevX == x) {
            if (y > prevY) {
                answer.pop_back();                    
                answer.push_back({x, y});
                return;
            }
        }

        if (prevY == y) {
            if (x < prevX) {
                answer.pop_back();                    
                answer.push_back({x, y});
            }
        }
    }
};

int main() {
    Solution soln;
    // vector<vector<int>> buildings = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    vector<vector<int>> buildings = {{0,2,3},{2,5,3}};
    vector<vector<int>> answer = soln.getSkyline(buildings);

    return 0;
}