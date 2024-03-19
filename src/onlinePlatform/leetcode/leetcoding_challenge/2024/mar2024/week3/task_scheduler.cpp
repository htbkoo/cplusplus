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
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counter;
        for (auto task: tasks) {
            counter[task]++;
        }

        auto cmp = [&](char left, char right) { return counter[left] < counter[right]; };
        priority_queue<char, vector<char>, decltype(cmp)> pq(cmp);
        for (auto& [task, count]: counter) {
            pq.push(task);
        }
        //         priority_queue<pair<int, char>> pq;
        //         for (auto& [task, count]: counter) {
        //             pq.push(pair{count, task});
        //         }

        deque<pair<int, char>> cooldowns;

        int time = 0;
        while (pq.size() > 0 || cooldowns.size() > 0) {
            while (cooldowns.size() > 0 && time >= cooldowns[0].first) {
                auto [_, task] = cooldowns.front();
                pq.push(task);
                cooldowns.pop_front();
            }

            if (pq.size() > 0) {
                auto task = pq.top();
                pq.pop();

                time++;
                counter[task]--;

                if (counter[task] > 0) {
                    cooldowns.push_back(pair{time + n, task});
                }
            } else {
                auto [newTime, task] = cooldowns.front();
                pq.push(task);
                cooldowns.pop_front();
                time = newTime;
            }
        }

        return time;
    }
};
