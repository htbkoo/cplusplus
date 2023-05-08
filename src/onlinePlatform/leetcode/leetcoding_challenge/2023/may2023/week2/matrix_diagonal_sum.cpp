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
    int diagonalSum(vector<vector<int>>& mat) {
        // TODO: validate input, e.g. mat is square matrix; answer fits within int
        
        int answer = 0;
        
        for (int i = 0; i < mat.size(); ++i) {
            answer += mat[i][i];
            if (i != mat.size() - 1 - i) {
                answer += mat[i][mat.size() - 1 - i];
            }
        }
        
        return answer;
    }
};