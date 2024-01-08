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
const int UNINITIALIZED = -1;

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        // int height = binaryMatrix.size();
        // int width = binaryMatrix[0].size();
        // auto dimensions = binaryMatrix.dimensions();
        int height = binaryMatrix.dimensions()[0];
        int width = binaryMatrix.dimensions()[1];

        int y = 0;
        int x = width - 1;

        while (y < height and x >= 0) {
            if (binaryMatrix.get(y, x) == 1) {
                x--;
            } else {
                y++;
            }
        }

        if (x + 1 < width) {
            return x + 1;
        } else {
            return -1;
        }
    }
};