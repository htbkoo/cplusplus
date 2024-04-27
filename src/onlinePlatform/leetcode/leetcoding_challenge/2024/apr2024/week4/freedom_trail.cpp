#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <limits>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iterator>
#include <sstream>
#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text
const int UNINITIALIZED = -1;
const int INVALID = numeric_limits<int>::max() / 2;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        memo = vector<vector<int>>();
        visited = vector<vector<bool>>();
        for (int k = 0; k < key.size(); ++k) {
            memo.push_back(vector<int>(ring.size(), UNINITIALIZED));
            visited.push_back(vector<bool>(ring.size(), false));
        }
        
        int START_RING_POS = 0;
        return findMin(ring, key, 0, START_RING_POS);
    }
    
private:
    vector<vector<int>> memo;
    vector<vector<bool>> visited;
    
    int findMin(string& ring, string& key, int k, int r) {
        if (visited[k][r]) {
            return INVALID;
        }
        visited[k][r] = true;
            
        if (k >= key.size()) {
            return 0;
        }
        
        if (memo[k][r] == UNINITIALIZED) {
            if (key[k] == ring[r]) {
                return 1 + findMin(ring, key, k + 1, r);
            } else {
                return 1 + min(
                    findMin(ring, key, k, (r + ring.size() + 1) % ring.size()),
                    findMin(ring, key, k, (r + ring.size() - 1) % ring.size())
                );
            }
        }
        
        return memo[k][r];
    }
    
};

int main() {
    cout << Solution().findRotateSteps("godding", "gd") << endl;
    return 0;
}