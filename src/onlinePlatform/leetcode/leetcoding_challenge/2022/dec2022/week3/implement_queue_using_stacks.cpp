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

class MyQueue {
public:
    MyQueue() {
        inStack = vector<int>();
        outStack = vector<int>();
    }
    
    void push(int x) {
        inStack.push_back(x);
    }
    
    int pop() {
        // TODO: handle edge cases, e.g. when Queue is empty
        populateOutStack();
        int val = outStack.back();
        outStack.pop_back();
        return val;        
    }
    
    int peek() {
        populateOutStack();
        return outStack.back();
    }
    
    bool empty() {
        return inStack.size() == 0 && outStack.size() == 0;
    }
    
private:
    vector<int> inStack;
    vector<int> outStack;
    
    void populateOutStack() {
        if (outStack.size() == 0) {
            while (inStack.size() > 0) {
                outStack.push_back(inStack.back());
                inStack.pop_back();
            }
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */