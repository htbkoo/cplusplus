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

const int MAX_NUM_KEY = 1e6;

class MyHashSet {
public:
    MyHashSet() {
        memset(arr, false, sizeof(arr));
    }
    
    void add(int key) {
        arr[key] = true;
     }
    
    void remove(int key) {
        arr[key] = false;
    }
    
    bool contains(int key) {
        return arr[key];
    }
    
private:
    bool arr[MAX_NUM_KEY + 1];
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */