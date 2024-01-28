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
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int HEIGHT = matrix.size();
        int WIDTH = matrix[0].size();

        vector<vector<int>> prefix;
        for (int y = 0; y <= HEIGHT; y++) {
            prefix.push_back(vector<int>(WIDTH + 1, 0));
        }

        for (int y = 0; y < HEIGHT; y++) {
            prefix[y + 1][1] = prefix[y][1] + matrix[y][0];
        }
        for (int x = 1; x < WIDTH; x++) {
            prefix[1][x + 1] = prefix[1][x] + matrix[0][x];
        }

        for (int y = 1; y < HEIGHT; y++) {
            for (int x = 1; x < WIDTH; x++) {
                prefix[y + 1][x + 1] = matrix[y][x] + prefix[y][x + 1] + prefix[y + 1][x] - prefix[y][x];
            }
        }

        int answer = 0;
        for (int x1 = 0; x1 <= WIDTH; x1++) {
            for (int x2 = x1 + 1; x2 <= WIDTH; x2++) {
                unordered_map<int, int> counter;
                for (int y = 0; y <= HEIGHT; y++) {
                    int curr = prefix[y][x2] - prefix[y][x1];
                    answer += counter[curr - target];
                    counter[curr]++;
                }
            }
        }

        return answer;
    }
};

int main() {
    Solution soln;

    vector<vector<int>> matrix{{0,1,0},{1,1,1},{0,1,0}};
    cout << soln.numSubmatrixSumTarget(matrix, 0) << endl;

    return 0;
}