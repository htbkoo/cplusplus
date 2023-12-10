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
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int height = matrix.size();
        if (height == 0) {
            return {};
        }

        // TODO: what if matrix is not rectangular?

        int width = matrix[0].size();

        vector<vector<int>> answer;
        for (int i = 0; i < width; ++i) {
            answer.push_back(vector<int>(height));
            for (int j = 0; j < height; ++j) {
                answer[i][j] = matrix[j][i];
            }
        }

        return answer;
    }
};
