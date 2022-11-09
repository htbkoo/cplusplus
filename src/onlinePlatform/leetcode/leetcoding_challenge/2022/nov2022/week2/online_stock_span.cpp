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


class StockSpanner {
public:
    StockSpanner() {
        stack = vector<pair<int, int>>();
    }
    
    int next(int price) {
        int count = 1;
        while (stack.size() > 0) {
            auto [prevPrice, prevCount] = stack.back();
            stack.pop_back();
            
            if (price >= prevPrice) {
                count += prevCount;
            } else {
                stack.push_back(pair<int, int>{prevPrice, prevCount});
                break;
            }
        }
        
        stack.push_back(pair<int, int>{price, count});
        return count;
    }
    
private:
    vector<pair<int, int>> stack;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */