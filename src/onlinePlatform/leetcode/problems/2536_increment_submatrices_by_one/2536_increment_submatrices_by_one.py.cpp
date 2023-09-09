#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> answer;
        for (int i = 0; i < n; ++i) {
            answer.push_back(vector<int>(n, 0));
        }

        for (vector<int> query: queries) {
            int xTop = query[0], yLeft = query[1], xBottom = query[2], yRight = query[3];
            
            answer[xTop][yLeft] += 1;
            if (xBottom + 1 < n) {
                answer[xBottom + 1][yLeft] -= 1;
            }
            if (yRight + 1 < n) {
                answer[xTop][yRight + 1] -= 1;
            }
            if (xBottom + 1 < n && yRight + 1 < n) {
                answer[xBottom + 1][yRight + 1] += 1;
            }
        }

        for (int x = 0; x < n; ++x) {
            for (int y = 1; y < n; ++y) {
                answer[x][y] += answer[x][y - 1];
            }
        }

        for (int y = 0; y < n; ++y) {
            for (int x = 1; x < n; ++x) {
                answer[x][y] += answer[x - 1][y];
            }
        }

        return answer;
    }
};