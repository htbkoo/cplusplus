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

class NumberContainers {
    unordered_map<int, int> arr;
    unordered_map<int, set<int>> container;
    
public:
    NumberContainers() {
        arr = unordered_map<int, int>();
        container = unordered_map<int, set<int>>();
    }
    
    void change(int index, int number) {
        // 1. remove from container if it is already asssigned in arr
        if (arr.count(index) > 0) {
            auto currNum = arr[index];
            container[currNum].erase(index);
            if (container[currNum].size() == 0) {
                container.erase(currNum);
            }
        }

        arr[index] = number;
        container[number].insert(index);
    }
    
    int find(int number) {
        if (container.count(number) == 0) {
            return -1;
        }
        return *begin(container[number]);
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */