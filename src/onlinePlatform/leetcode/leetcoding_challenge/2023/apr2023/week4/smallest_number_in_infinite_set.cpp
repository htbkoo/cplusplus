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
#include <cstring> // for memset
using namespace std; // since cin and cout are both in namespace std, this saves some text

class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        appeared = unordered_set<int>();
        pq = priority_queue<int>();
        counter = 1;
    }
    
    int popSmallest() {
        if (pq.empty() || counter <= pq.top()) {
            int val = counter;
            counter++;
            return val;
        } else {
            int val = -pq.top();
            pq.pop();
            appeared.erase(val);
            return val;
        }
    }
    
    void addBack(int num) {
        if (num < counter && appeared.count(num) == 0) {
            pq.push(-num);
            appeared.insert(num);
        }
    }
    
private:
    unordered_set<int> appeared;
    priority_queue<int> pq;
    int counter;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */