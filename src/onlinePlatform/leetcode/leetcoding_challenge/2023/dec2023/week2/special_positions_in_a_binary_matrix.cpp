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
    int numSpecial(vector<vector<int>>& mat) {
        int height = mat.size();
        int width = mat[0].size();

        vector<int> rowsCounts(height, 0);
        vector<int> colsCounts(width, 0);

        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                if (mat[y][x] == 1) {
                    rowsCounts[y]++;
                    colsCounts[x]++;
                }
            }
        }

        int answer = 0;
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                if (mat[y][x] == 1 && rowsCounts[y] == 1 && colsCounts[x] == 1) {
                    answer++;
                }
            }
        }

        return answer;
    }
};

int main() {
    Solution soln;

    vector<vector<int>> mat{{1, 0, 0}, {0, 0, 1}, {1, 0, 0}};
    // vector<vector<int>> mat{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

    cout << soln.numSpecial(mat) << endl;

    return 0;
}
