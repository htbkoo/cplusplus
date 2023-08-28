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

const int NO_LAST = -1;

class MyStack {
public:
    MyStack() {
        q = queue<int>();
    }
    
    void push(int x) {
        if (last != NO_LAST) {
            q.push(last);
        }
        last = x;
    }
    
    int pop() {
        int val = top();
        last = NO_LAST;
        return val;
    }
    
    int top() {
        if (last == NO_LAST) {
            for (int i = 0; i < q.size() - 1; ++i) {
                q.push(q.front());
                q.pop();
            }
            last = q.front();
            q.pop();
        }   
        return last;
    }
    
    bool empty() {
        return last == NO_LAST && q.size() == 0;
    }
    
private:
    queue<int> q;
    int last = NO_LAST;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */