#include <algorithm>
#include <vector>
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
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int height = mat.size();
        int width = mat[0].size();

        vector<vector<int>> answer;
        for (int y = 0; y < height; y++) {
            answer.push_back(vector<int>(width));
        }

        for (int x = 0; x < width; x++) {
            vector<int> diag = getSortedDiag(mat, x, 0);
            fill(diag, answer, x, 0);
        }

        for (int y = 1; y < height; y++) {
            vector<int> diag = getSortedDiag(mat, 0, y);
            fill(diag, answer, 0, y);
        }

        return answer;
    }

    vector<int> getSortedDiag(vector<vector<int>>& mat, int x, int y) {        
        int height = mat.size();
        int width = mat[0].size();

        vector<int> diag;

        while (x < width && y < height) {
            diag.push_back(mat[y][x]);
            y++;
            x++;
        }

        sort(diag.begin(), diag.end());

        return diag;
    }

    void fill(vector<int> diag, vector<vector<int>>& mat, int x, int y) {
        int height = mat.size();
        int width = mat[0].size();

        for (int i = 0; i < diag.size(); i++) {
            mat[y][x] = diag[i];            
            y++;
            x++;
        }
    }
};

int main() {
    Solution soln;

    vector<int> row1 = {3,3,1,1};
    vector<int> row2 = {2,2,1,2};
    vector<int> row3 = {1,1,1,2};    
    vector<vector<int>> mat = {row1, row2, row3};
    vector<vector<int>> answer = soln.diagonalSort(mat);

    return 0;
}