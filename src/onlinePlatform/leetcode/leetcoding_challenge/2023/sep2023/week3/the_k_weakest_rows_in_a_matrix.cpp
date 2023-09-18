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
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>> pq;
        
        for (int row = 0; row < mat.size(); row++) {
            int numSoldiers = getCount(mat[row]);
            
            pq.push(pair{numSoldiers, row});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<int> answer;
        while (pq.size() > 0) {
            auto [_, row] = pq.top();
            pq.pop();
            answer.push_back(row);
        }
        
        reverse(answer.begin(), answer.end());
        return answer;
    }
    
private:
    int getCount(vector<int>& row) {        
        for (int c = 0; c < row.size(); c++) {
            if (row[c] == 0) {
                return c;
            }
        }
        return row.size();
    }
};