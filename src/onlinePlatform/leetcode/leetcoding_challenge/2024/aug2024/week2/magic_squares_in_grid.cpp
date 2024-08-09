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

int SQUARE_SIZE = 3;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int answer = 0;
        
        int height = grid.size();
        int width = grid[0].size();
        
        for (int y = 0; y <= (height - SQUARE_SIZE); ++y) {
            for (int x = 0; x <= (width - SQUARE_SIZE); ++x) {
                if (isMagicSquare(grid, y, x)) {
                    answer++;
                }
            }
        }
        
        return answer;
    }

private:
    bool isMagicSquare(vector<vector<int>>& grid, int y, int x) {
        unordered_set<int> nums;
        for (int cy = y; cy < y + SQUARE_SIZE; ++cy) {
            for (int cx = x; cx < x + SQUARE_SIZE; ++cx) {
                int num = grid[cy][cx];
                bool isWithinRange = 1 <= num && num <= (SQUARE_SIZE * SQUARE_SIZE);
                if (!isWithinRange) {
                    return false;
                }
                nums.insert(num);
            }
        }
            
        if (nums.size() != (SQUARE_SIZE * SQUARE_SIZE)) {
            return false;
        }
        
        int expectedSum = 0;
        for (int cx = x; cx < x + SQUARE_SIZE; ++cx) {
            int num = grid[y][cx];
            expectedSum += num;
        }
        
        // rows
        for (int cy = y; cy < y + SQUARE_SIZE; ++cy) {
            int sum = 0;
            for (int cx = x; cx < x + SQUARE_SIZE; ++cx) {
                int num = grid[cy][cx];
                sum += num;
            }
            if (sum != expectedSum) {
                return false;
            }
        }
        
        // cols
       for (int cx = x; cx < x + SQUARE_SIZE; ++cx) {
            int sum = 0;
            for (int cy = y; cy < y + SQUARE_SIZE; ++cy) {
                int num = grid[cy][cx];
                sum += num;
            }
            if (sum != expectedSum) {
                return false;
            }
        }    
        
        // diag
        int diagSum = 0;
        for (int i = 0; i < SQUARE_SIZE; ++i) {
            int num = grid[y + i][x + i];
            diagSum += num;            
        }
        if (diagSum != expectedSum) {
            return false;
        }
        
        // anti-diag
        int antiSum = 0;
        for (int i = 0; i < SQUARE_SIZE; ++i) {
            int num = grid[y + i][x + SQUARE_SIZE - 1 - i];
            antiSum += num;            
        }
        if (antiSum != expectedSum) {
            return false;
        }
        
        return true;
    }
};

int main() {
    Solution soln;
    vector<vector<int>> grid{{4,3,8,4},{9,5,1,9},{2,7,6,2}};
    cout << soln.numMagicSquaresInside(grid) << endl;
    return 0;
}