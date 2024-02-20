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
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> counts(n, 0);

        priority_queue<int> available;
        priority_queue<pair<long, int>> occupied;
        for (int i = 0; i < n; ++i) {
            available.push(-i);
        }

        sort(begin(meetings), end(meetings));

        long currTime = 0;

        for (auto& meeting: meetings) {
            int start = meeting[0], end = meeting[1];

            long duration = end - start;

            currTime = max(currTime, (long) start);
            if (available.size() == 0) {
                currTime = max(currTime, -occupied.top().first);
            }

            while (occupied.size() > 0) {
                auto [negTime, negRoom] = occupied.top();
                auto time = -negTime;
                if (time > currTime) {
                    break;
                }
                occupied.pop();

                available.push(negRoom);
            }

            auto negRoom = available.top();
            available.pop();

            counts[-negRoom]++;

            occupied.push(pair{-(currTime + duration), negRoom});
        }

        int answer = 0;
        for (int i = 0; i < n; ++i) {
            if (counts[i] > counts[answer]) {
                answer = i;
            }
        }

        return answer;
    }
};

class WASolution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> counts(n, 0);

        priority_queue<int> available;
        priority_queue<pair<int, int>> occupied;
        for (int i = 0; i < n; ++i) {
            available.push(-i);
        }

        sort(begin(meetings), end(meetings));

        for (auto& meeting: meetings) {
            int start = meeting[0], end = meeting[1];

            int duration = end - start;

            // if (occupied.size() > 0) {
            if (available.size() == 0) {
                start = max(start, -occupied.top().first);
            }


            while (occupied.size() > 0) {
                auto [negTime, negRoom] = occupied.top();
                auto time = -negTime;
                if (time > start) {
                    break;
                }
                occupied.pop();

                available.push(negRoom);
            }

            auto negRoom = available.top();
            available.pop();

            counts[-negRoom]++;

            occupied.push(pair{-(start + duration), negRoom});
        }

        int answer = 0;
        for (int i = 0; i < n; ++i) {
            if (counts[i] > counts[answer]) {
                answer = i;
            }
        }

        return answer;
    }
};

int main() {
    Solution soln;
    // vector<vector<int>> meetings{{0,10},{1,5},{2,7},{3,4}};
    // cout << soln.mostBooked(2, meetings) << endl;

    // vector<vector<int>> meetings{{1,20},{2,10},{3,5},{4,9},{6,8}};
    // cout << soln.mostBooked(3, meetings) << endl;

    // cout << soln.mostBooked(100, meetings) << endl;

    cout << soln.mostBooked(10, meetings) << endl;

    return 0;
}