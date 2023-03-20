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
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i = 0;
        
        while (n > 0 && i < flowerbed.size()) {
            if (flowerbed[i] == 0) {
                bool isRightFlower = i < flowerbed.size() - 1 && flowerbed[i + 1] == 1;
                if (!isRightFlower) {
                    n--;
                    i += 2;
                } else {
                    i++;
                }                
            } else {
                i+=2;
            }
        }
            
        return n == 0;
    }
};
