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

int UNINITIALIZED = -1;

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<int> heights(books.size() + 1, numeric_limits<int>::max());
        heights[books.size()] = 0;
        for (int i = books.size() - 1; i >= 0; --i) {
            int j = i;
            int height = 0;
            int width = 0;
            while (j < books.size()) {
                height = max(height, books[j][1]);
                width += books[j][0]; 
                if (width > shelfWidth) {
                    break;
                }
                heights[i] = min(heights[i], height + heights[j + 1]);                
                j++;
            }            
        }
        
        return heights[0];
        
        // memo = vector<vector<int>>(books.size() + 1, vector<int>(shelfWidth + 1, UNINITIALIZED));
    }

// private:
//     vector<vector<int>> memo;
    
//     int findHeight(vector<vector<int>>& books, int shelfWidth, int i, int remainWidth) {
//         // TODO: what if max width > shelfWidth
//         if (i >= books.size()) {
//             return 0;
//         }
        
        
        
//         if (memo[i][remainWidth]) {
            
//         }
//     }
};
