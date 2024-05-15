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
    int numberOfCleanRooms(vector<vector<int>>& room) {
        int HEIGHT = room.size();
        int WIDTH = room[0].size();

        // map<char, pair<int, int>> DIRECTIONS = {{'T', pair{-1, 0}}, {'D', pair{1, 0}}, {'L', pair{0, -1}}, {'R', pair{0, 1}}};
        vector<pair<int, int>> DIRECTIONS{ pair{0, 1}, pair{1, 0}, pair{0, -1}, pair{-1, 0} };

        vector<vector<bool>> cleaned(HEIGHT, vector<bool>(WIDTH, false));

        set<tuple<int, int, int>> visited;

        int answer = 0;

        int y = 0;
        int x = 0;
        int d = 0;

        while (visited.count(tuple{y, x, d}) == 0) {
            visited.insert(tuple{y, x, d});

            auto [dy, dx] = DIRECTIONS[d];

            while (true) {
                if (!cleaned[y][x]) {
                    answer++;
                    cleaned[y][x] = true;
                }

                if (canMove(room, y + dy, x + dx)) {
                    y += dy;
                    x += dx;
                } else {
                    break;
                }
            }

            d = (d + 1) % DIRECTIONS.size();
        }

        return answer;
    }

private:
    bool canMove(vector<vector<int>>& room, int y, int x) {
        int HEIGHT = room.size();
        int WIDTH = room[0].size();

        bool isWithinBoundary = 0 <= y && y < HEIGHT && 0 <= x && x < WIDTH;
        if (!isWithinBoundary) {
            return false;
        }

        int OBJECT = 1;
        if (room[y][x] == OBJECT) {
            return false;
        }

        return true;
    }
};

class WIPSolution {
public:
    int numberOfCleanRooms(vector<vector<int>>& room) {
        int HEIGHT = room.size();
        int WIDTH = room[0].size();

        map<char, pair<int, int>> DIRECTIONS = {{'T', pair{-1, 0}}, {'D', pair{1, 0}}, {'L', pair{-1, 0}}, {'R', pair{0, 1}}};

        vector<vector<bool>> cleaned(HEIGHT, vector<bool>(WIDTH, false));

        set<tuple<int, int, char>> visited;

        int answer = 0;

        int y = 0;
        int x = 0;
        char d = 'R';

        while (visited.count(tuple{y, x, d}) == 0) {
            visited.insert(tuple{y, x, d});

            auto [dy, dx] =DIRECTIONS[d];

            while (true) {
                if (!cleaned[y][x]) {
                    answer++;
                    cleaned[y][x] = true;
                }

                // if (canMove(y + dy, x + dx)) {
                if (canMove(room)) {
                    y += dy;
                    x += dx;
                } else {
                    break;
                }
            }

        }

        return answer;
    }

private:
    bool canMove(vector<vector<int>>& room) {
        return false;
    }
};
