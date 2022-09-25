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
#include <string>
#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text

class MyCircularQueue {
public:
    vector<int> q;
    int lo = 0;
    int k;
    
    MyCircularQueue(int k) {
        this->k = k;
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        } else {            
            q.push_back(value);
            return true;
        }
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        } else {
            lo++;
            return true;
        }
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        } else {
            return q[lo];
        }
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        } else {
            return q[q.size() - 1];
        }        
    }
    
    bool isEmpty() {
        return _size() == 0;
    }
    
    bool isFull() {
        return _size() >= k;
    }

private:
    int _size() {
        return q.size() - lo;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */