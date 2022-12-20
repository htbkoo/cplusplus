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
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> keys;

        vector<int> stack = {0};

        while (stack.size() > 0) {
            int room = stack.back();
            stack.pop_back();

            if (keys.count(room) > 0) {
                continue;
            }
            keys.insert(room);

            for (int pickUp: rooms[room]) {
                stack.push_back(pickUp);
            }
        }

        return keys.size() == rooms.size();
    }
};

class FirstSolution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> keys = unordered_set<int>({0});
        unordered_set<int> visited;

        vector<int> stack = {0};

        while (stack.size() > 0) {
            int room = stack.back();
            stack.pop_back();

            if (visited.count(room) > 0) {
                continue;
            }
            visited.insert(room);

            for (int pickUp: rooms[room]) {
                keys.insert(pickUp);
                stack.push_back(pickUp);
            }
        }

        return keys.size() == rooms.size();
    }
};
